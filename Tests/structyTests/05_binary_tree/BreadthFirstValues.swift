//
//  BreadthFirstValues.swift
//  MyCLI
//
//  Created by new on 3/23/26.
//

import Testing
@testable import structy

@Suite("05 BreadthFirstValuesTests")
struct BreadthFirstValuesTests {
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
            breadthFirstValues(a)
        }
        #expect(result == ["a", "b", "c", "d", "e", "f"])
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

        a.left = b
        a.right = c
        b.left = d
        b.right = e
        c.right = f
        e.left = g
        f.right = h

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            breadthFirstValues(a)
        }
        #expect(result == ["a", "b", "c", "d", "e", "f", "g", "h"])
    }

    @Test("test_02")
    func test02() async throws {
        let a = TreeNode("a")

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            breadthFirstValues(a)
        }
        #expect(result == ["a"])
    }

    @Test("test_03")
    func test03() async throws {
        let a = TreeNode("a")
        let b = TreeNode("b")
        let c = TreeNode("c")
        let d = TreeNode("d")
        let e = TreeNode("e")
        let x = TreeNode("x")

        a.right = b
        b.left = c
        c.left = x
        c.right = d
        d.right = e

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            breadthFirstValues(a)
        }
        #expect(result == ["a", "b", "c", "x", "d", "e"])
    }

    @Test("test_04")
    func test04() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            breadthFirstValues(nil)
        }
        #expect(result == [])
    }
}
