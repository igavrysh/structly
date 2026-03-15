//
//  TestSupport.swift
//  MyCLI
//
//  Created by new on 3/10/26.
//

import Foundation

extension Task where Success == Never, Failure == Never {
    static var isDebuggerAttached: Bool {
        var info = kinfo_proc()
        var mib: [Int32] = [CTL_KERN, KERN_PROC, KERN_PROC_PID, getpid()]
        var size = MemoryLayout<kinfo_proc>.size
        let junk = sysctl(&mib, UInt32(mib.count), &info, &size, nil, 0)
        assert(junk == 0, "sysctl failed")
        return (info.kp_proc.p_flag & P_TRACED) != 0
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
                try await Task.sleep(for: Task.isDebuggerAttached ? .seconds(3600) : .seconds(seconds))
                throw TimeoutError()
            }
            let result = try await group.next()!
            group.cancelAll()
            return result
        }
    }
}
