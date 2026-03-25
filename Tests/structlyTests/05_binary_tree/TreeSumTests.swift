//
//  TreeSum.swift
//  MyCLI
//
//  Created by new on 3/24/26.
//

import Testing
@testable import structly

@Suite("05_TreeSumTests")
struct TreeSumTests {
    @Test("test_00")
    func test00() async throws {
        let a = TreeNode(3)
        let b = TreeNode(11)
        let c = TreeNode(4)
        let d = TreeNode(4)
        let e = TreeNode(-2)
        let f = TreeNode(1)

        a.left = b
        a.right = c
        b.left = d
        b.right = e
        c.right = f

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            treeSum(a)
        }
        #expect(result == 21)
    }

    @Test("test_01")
    func test01() async throws {
        let a = TreeNode(1)
        let b = TreeNode(6)
        let c = TreeNode(0)
        let d = TreeNode(3)
        let e = TreeNode(-6)
        let f = TreeNode(2)
        let g = TreeNode(2)
        let h = TreeNode(2)

        a.left = b
        a.right = c
        b.left = d
        b.right = e
        c.right = f
        e.left = g
        f.right = h

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            treeSum(a)
        }
        #expect(result == 10)
    }

    @Test("test_02")
    func test02() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            treeSum(nil)
        }
        #expect(result == 0)
    }
}
