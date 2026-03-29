//
//  CommonTests.swift
//  MyCLI
//
//  Created by new on 3/29/26.
//

import Testing
@testable import structy

@Suite("CommonTests")
struct CommonTests {
    @Test("test_00")
    func test00() async throws {

        class NonSendableCounter { var count = 0 }

        let node = TreeNode(NonSendableCounter())

        Task.detached {
            print(node.val.count) // This should trigger a warning if Strict Concurrency is 'Complete'
        }
    }
}
