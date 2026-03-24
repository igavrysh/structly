//
//  DepthFirstValuesTests.swift
//  MyCLI
//
//  Created by new on 3/23/26.
//
import Testing
@testable import structly

@Suite("05_DepthFirstValuesTests")
struct DepthFirstValuesTests {
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
            depthFirstValues(a)
        }
        #expect(result == ["a", "b", "d", "e", "c", "f"])
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

        a.left = b
        a.right = c
        b.left = d
        b.right = e
        c.right = f
        e.left = g

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            depthFirstValues(a)
        }
        #expect(result == ["a", "b", "d", "e", "g", "c", "f"])
    }

    @Test("test_02")
    func test02() async throws {
        let a = TreeNode("a")

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            depthFirstValues(a)
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

        a.right = b
        b.left = c
        c.right = d
        d.right = e

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            depthFirstValues(a)
        }
        #expect(result == ["a", "b", "c", "d", "e"])
    }

    @Test("test_04")
    func test04() async throws {
        let a: TreeNode<String>? = nil
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            depthFirstValues(a)
        }
        #expect(result == [])
    }
}
