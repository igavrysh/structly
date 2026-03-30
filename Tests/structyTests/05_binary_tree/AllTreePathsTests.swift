//
//  AllTreePathsTests.swift
//  MyCLI
//
//  Created by new on 3/29/26.
//

import Testing
@testable import structy

@Suite("05 AllTreePathsTests")
struct AllTreePathsTests {
    private func normalized(_ paths: [[String]]) -> [[String]] {
        return paths.sorted { $0.joined(separator: "/") < $1.joined(separator: "/") }
    }

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
            allTreePaths(a)
        }
        let expected = [
            ["a", "b", "d"],
            ["a", "b", "e"],
            ["a", "c", "f"]
        ]
        #expect(normalized(result) == normalized(expected))
    }

    @Test("test_01")
    func test01() async throws {
        let a = TreeNode("a")
        let b = TreeNode("b")
        let c = TreeNode("c")
        let d = TreeNode("d")
        let e = TreeNode("e")
        let f = TreeNode("f")
        let g = TreeNode("g")
        let h = TreeNode("h")
        let i = TreeNode("i")

        a.left = b
        a.right = c
        b.left = d
        b.right = e
        c.right = f
        e.left = g
        e.right = h
        f.left = i

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            allTreePaths(a)
        }
        let expected = [
            ["a", "b", "d"],
            ["a", "b", "e", "g"],
            ["a", "b", "e", "h"],
            ["a", "c", "f", "i"]
        ]
        #expect(normalized(result) == normalized(expected))
    }

    @Test("test_02")
    func test02() async throws {
        let q = TreeNode("q")
        let r = TreeNode("r")
        let s = TreeNode("s")
        let t = TreeNode("t")
        let u = TreeNode("u")
        let v = TreeNode("v")

        q.left = r
        q.right = s
        r.right = t
        t.left = u
        u.right = v

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            allTreePaths(q)
        }
        let expected = [
            ["q", "r", "t", "u", "v"],
            ["q", "s"]
        ]
        #expect(normalized(result) == normalized(expected))
    }

    @Test("test_03")
    func test03() async throws {
        let z = TreeNode("z")

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            allTreePaths(z)
        }
        #expect(result == [["z"]])
    }
}
