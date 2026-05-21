//
//  HowHighTests.swift
//  MyCLI
//
//  Created by new on 3/29/26.
//

import Testing
@testable import structy
@Suite
final class HowHighTests {
    @Test
    func test00() async throws {
        let a = TreeNode("a")
        let b = TreeNode("b")
        let c = TreeNode("c")
        let d = TreeNode("d")
        let e = TreeNode("e")
        let f = TreeNode("f")

        a.left = b
        a.right = c
        b.left = d
        b.right = e
        c.right = f

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            howHigh(a)
        }

        //      a
        //    /   \
        //   b     c
        //  / \     \
        // d   e     f

        #expect(result == 2)
    }

    @Test
    func test01() async throws {
        let a = TreeNode("a")
        let b = TreeNode("b")
        let c = TreeNode("c")
        let d = TreeNode("d")
        let e = TreeNode("e")
        let f = TreeNode("f")
        let g = TreeNode("g")

        a.left = b
        a.right = c
        b.left = d
        b.right = e
        c.right = f
        e.left = g

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            howHigh(a)
        }

        //      a
        //    /   \
        //   b     c
        //  / \     \
        // d   e     f
        //    /
        //   g

        #expect(result == 3)
    }

    @Test
    func test02() async throws {
        let a = TreeNode("a")
        let c = TreeNode("c")

        a.right = c

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            howHigh(a)
        }

        //      a
        //       \
        //        c

        #expect(result == 1)
    }

    @Test
    func test03() async throws {
        let a = TreeNode("a")

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            howHigh(a)
        }

        //      a

        #expect(result == 0)
    }

    @Test
    func test04() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            howHigh(nil)
        }
        #expect(result == -1)
    }

    @Test
    func test05() async throws {
        let height_nodes = 32000
        let root = TreeNode(String(0))
        var current = root
        for i in 1..<height_nodes {
            let next = TreeNode(String(i))
            current.right = next
            current = next
        }
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            howHigh(root)
        }
        let expected = height_nodes - 1
        #expect(result == expected)
    }
}
