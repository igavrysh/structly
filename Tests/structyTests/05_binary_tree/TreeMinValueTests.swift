//
//  TreeMinValueTests.swift
//  MyCLI
//
//  Created by new on 3/25/26.
//

import Testing
@testable import structy

@Suite("05_TreeMinValueTests")
struct TreeMinValueTests {
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
            treeMinValue(a)
        }
        #expect(result == -2)
    }

    @Test("test_01")
    func test01() async throws {
        let a = TreeNode(5)
        let b = TreeNode(11)
        let c = TreeNode(3)
        let d = TreeNode(4)
        let e = TreeNode(14)
        let f = TreeNode(12)

        a.left = b
        a.right = c
        b.left = d
        b.right = e
        c.right = f

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            treeMinValue(a)
        }
        #expect(result == 3)
    }

    @Test("test_02")
    func test02() async throws {
        let a = TreeNode(-1)
        let b = TreeNode(-6)
        let c = TreeNode(-5)
        let d = TreeNode(-3)
        let e = TreeNode(-4)
        let f = TreeNode(-13)
        let g = TreeNode(-2)
        let h = TreeNode(-2)

        a.left = b
        a.right = c
        b.left = d
        b.right = e
        c.right = f
        e.left = g
        f.right = h

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            treeMinValue(a)
        }
        #expect(result == -13)
    }

    @Test("test_03")
    func test03() async throws {
        let a = TreeNode(42)

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            treeMinValue(a)
        }
        #expect(result == 42)
    }
}
