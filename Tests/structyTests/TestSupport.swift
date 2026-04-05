//
//  TestSupport.swift
//  MyCLI
//
//  Created by new on 3/10/26.
//

import Foundation

#if canImport(Darwin)
import Darwin
#elseif os(Linux)
import Glibc
#endif

extension Task where Success == Never, Failure == Never {
    static var isDebuggerAttached: Bool {
        #if os(macOS) || os(iOS) || os(tvOS) || os(watchOS)
        // Darwin Implementation (System Control)
        var info = kinfo_proc()
        var mib: [Int32] = [CTL_KERN, KERN_PROC, KERN_PROC_PID, getpid()]
        var size = MemoryLayout<kinfo_proc>.size
        let junk = sysctl(&mib, UInt32(mib.count), &info, &size, nil, 0)
        assert(junk == 0, "sysctl failed")
        return (info.kp_proc.p_flag & P_TRACED) != 0

        #elseif os(Linux)
        // Linux Implementation (Proc Filesystem)
        // Look for "TracerPid" in /proc/self/status. 
        // If it's 0, no debugger is attached.
        guard let status = try? String(contentsOfFile: "/proc/self/status") else {
            return false
        }
        
        let lines = status.split(separator: "\n")
        for line in lines {
            if line.contains("TracerPid:") {
                let parts = line.split(separator: ":")
                if parts.count > 1 {
                    let tracerPid = parts[1].trimmingCharacters(in: .whitespaces)
                    return tracerPid != "0"
                }
            }
        }
        return false

        #else
        // Fallback for other platforms (Windows, Android, etc.)
        return false
        #endif
    }
}

enum TimeoutSupport {
    struct TimeoutError: Error {}

    static func runWithTimeout<T: Sendable>(
        seconds: Int,
        operation: @escaping @Sendable () -> T
    ) async throws -> T {
        try await withThrowingTaskGroup(of: T.self) { group in
            group.addTask {
                operation()
            }
            group.addTask {
                let secs = Task.isDebuggerAttached ? Duration.seconds(5) : Duration.seconds(seconds)
                try await Task.sleep(for: secs)
                throw TimeoutError()
            }
            let result = try await group.next()!
            group.cancelAll()
            return result
        }
    }
}
