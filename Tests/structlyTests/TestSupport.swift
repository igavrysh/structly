//
//  TestSupport.swift
//  MyCLI
//
//  Created by new on 3/10/26.
//

import Foundation

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
                try await Task.sleep(for: .seconds(seconds))
                throw TimeoutError()
            }
            let result = try await group.next()!
            group.cancelAll()
            return result
        }
    }
}
