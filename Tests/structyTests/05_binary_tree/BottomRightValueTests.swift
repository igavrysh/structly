//
//  BottomRightValueTests.swift
//  MyCLI
//
//  Created by new on 3/29/26.
//

import Testing
@testable import structy

@Suite("05 BottomRightValueTests")
struct BottomRightValueTests {
    @Test("test_00")
    func test00() async throws {
        let a = TreeNode(3)
        let b = TreeNode(11)
        let c = TreeNode(10)
        let d = TreeNode(4)
        let e = TreeNode(-2)
        let f = TreeNode(1)

        a.left = b
        a.right = c
        b.left = d
        b.right = e
        c.right = f

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            bottomRightValue(a)
        }

        //       3
        //    /    \
        //   11     10
        //  / \      \
        // 4   -2     1

        #expect(result == 1)
    }

    @Test("test_01")
    func test01() async throws {
        let a = TreeNode(-1)
        let b = TreeNode(-6)
        let c = TreeNode(-5)
        let d = TreeNode(-3)
        let e = TreeNode(-4)
        let f = TreeNode(-13)
        let g = TreeNode(-2)
        let h = TreeNode(6)

        a.left = b
        a.right = c
        b.left = d
        b.right = e
        c.right = f
        e.left = g
        e.right = h

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            bottomRightValue(a)
        }

        //        -1
        //      /   \
        //    -6    -5
        //   /  \     \
        // -3   -4   -13
        //     / \
        //    -2  6

        #expect(result == 6)
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
        let h = TreeNode(6)
        let i = TreeNode(7)

        a.left = b
        a.right = c
        b.left = d
        b.right = e
        c.right = f
        e.left = g
        e.right = h
        f.left = i

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            bottomRightValue(a)
        }

        //        -1
        //      /   \
        //    -6    -5
        //   /  \     \
        // -3   -4   -13
        //     / \    /
        //    -2  6  7

        #expect(result == 7)
    }

    @Test("test_03")
    func test03() async throws {
        let a = TreeNode("a")
        let b = TreeNode("b")
        let c = TreeNode("c")
        let d = TreeNode("d")
        let e = TreeNode("e")
        let f = TreeNode("f")

        a.left = b
        a.right = c
        b.right = d
        d.left = e
        e.right = f

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            bottomRightValue(a)
        }

        //      a
        //    /   \
        //   b     c
        //    \
        //     d
        //    /
        //   e
        //   \
        //    f

        #expect(result == "f")
    }

    @Test("test_04")
    func test04() async throws {
        let a = TreeNode(42)

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            bottomRightValue(a)
        }

        //      42

        #expect(result == 42)
    }
}
