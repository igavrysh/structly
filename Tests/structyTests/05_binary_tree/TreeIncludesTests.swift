//
//  TreeIncludes.swift
//  MyCLI
//
//  Created by new on 3/24/26.
//

import Testing
@testable import structy
@Suite
final class TreeIncludesTests {
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
            treeIncludes(a, "e")
        }
        #expect(result == true)
    }

    @Test
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
            treeIncludes(a, "a")
        }
        #expect(result == true)
    }

    @Test
    func test02() async throws {
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
            treeIncludes(a, "n")
        }
        #expect(result == false)
    }

    @Test
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
            treeIncludes(a, "f")
        }
        #expect(result == true)
    }

    @Test
    func test04() async throws {
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
            treeIncludes(a, "p")
        }
        #expect(result == false)
    }

    @Test
    func test05() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            treeIncludes(nil, "b")
        }
        #expect(result == false)
    }
}
