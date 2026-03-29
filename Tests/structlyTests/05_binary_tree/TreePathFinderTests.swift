//
//  TreePathFinderTests.swift
//  MyCLI
//
//  Created by new on 3/27/26.
//

import Testing

@testable import structly

@Suite("05 PathFinderTests")
struct PathFinderTests {
    @Test("test_00")
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
            let res = pathFinder(a, "e")

            return res
        }
        #expect(result == ["a", "b", "e"])
    }

    @Test("test_01")
    func test01() async throws {
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
            pathFinder(a, "p")
        }
        #expect(result == [])
    }

    @Test("test_02")
    func test02() async throws {
        let a = TreeNode("a")
        let b = TreeNode("b")
        let c = TreeNode("c")
        let d = TreeNode("d")
        let e = TreeNode("e")
        let f = TreeNode("f")
        let g = TreeNode("g")
        let h = TreeNode("h")

        a.left = b
        a.right = c
        b.left = d
        b.right = e
        c.right = f
        e.left = g
        f.right = h

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            pathFinder(a, "c")
        }
        #expect(result == ["a", "c"])
    }

    @Test("test_03")
    func test03() async throws {
        let a = TreeNode("a")
        let b = TreeNode("b")
        let c = TreeNode("c")
        let d = TreeNode("d")
        let e = TreeNode("e")
        let f = TreeNode("f")
        let g = TreeNode("g")
        let h = TreeNode("h")

        a.left = b
        a.right = c
        b.left = d
        b.right = e
        c.right = f
        e.left = g
        f.right = h

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            pathFinder(a, "h")
        }
        #expect(result == ["a", "c", "f", "h"])
    }

    @Test("test_04")
    func test04() async throws {
        let x = TreeNode("x")

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            pathFinder(x, "x")
        }
        #expect(result == ["x"])
    }

    @Test("test_05")
    func test05() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            pathFinder(nil, "x")
        }
        #expect(result == [])
    }

    @Test("test_06")
    func test06() async throws {
        let root = TreeNode(0)
        var current = root
        for i in 1..<32000 {
            let next = TreeNode(i)
            current.right = next
            current = next
        }
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            pathFinder(root, 30000)
        }
        let expected = Array(0...30000)
        #expect(result == expected)
    }
}
