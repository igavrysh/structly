//
//  CommonTests.swift
//  MyCLI
//
//  Created by new on 3/29/26.
//

import Testing
@testable import structy
@Suite
final class CommonTests {
    @Test
    func test00() {
        let node = TreeNode(42)
        #expect(node.val == 42)
    }
}
