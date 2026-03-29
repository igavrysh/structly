//
//  TreeValueCount.swift
//  MyCLI
//
//  Created by new on 3/29/26.
//

import Testing
@testable import structly

@Suite("05 TreeValueCountTests")
struct TreeValueCountTests {
    @Test("test_00")
    func test00() async throws {
        let a = TreeNode(12)
        let b = TreeNode(6)
        let c = TreeNode(6)
        let d = TreeNode(4)
        let e = TreeNode(6)
        let f = TreeNode(12)

        a.left = b
        a.right = c
        b.left = d
        b.right = e
        c.right = f

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            treeValueCount(a, 6)
        }
        #expect(result == 3)
    }

    @Test("test_01")
    func test01() async throws {
        let a = TreeNode(12)
        let b = TreeNode(6)
        let c = TreeNode(6)
        let d = TreeNode(4)
        let e = TreeNode(6)
        let f = TreeNode(12)

        a.left = b
        a.right = c
        b.left = d
        b.right = e
        c.right = f

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            treeValueCount(a, 12)
        }
        #expect(result == 2)
    }

    @Test("test_02")
    func test02() async throws {
        let a = TreeNode(7)
        let b = TreeNode(5)
        let c = TreeNode(1)
        let d = TreeNode(1)
        let e = TreeNode(8)
        let f = TreeNode(7)
        let g = TreeNode(1)
        let h = TreeNode(1)

        a.left = b
        a.right = c
        b.left = d
        b.right = e
        c.right = f
        e.left = g
        f.right = h

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            treeValueCount(a, 1)
        }
        #expect(result == 4)
    }

    @Test("test_03")
    func test03() async throws {
        let a = TreeNode(7)
        let b = TreeNode(5)
        let c = TreeNode(1)
        let d = TreeNode(1)
        let e = TreeNode(8)
        let f = TreeNode(7)
        let g = TreeNode(1)
        let h = TreeNode(1)

        a.left = b
        a.right = c
        b.left = d
        b.right = e
        c.right = f
        e.left = g
        f.right = h

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            treeValueCount(a, 9)
        }
        #expect(result == 0)
    }

    @Test("test_04")
    func test04() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            treeValueCount(nil, 42)
        }
        #expect(result == 0)
    }

    @Test("test_05")
    func test06() async throws {
        let root = TreeNode(0)
        var current = root
        for i in 1..<32000 {
            let next = TreeNode(i)
            current.right = next
            current = next
        }
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            treeValueCount(root, 30000)
        }
        let expected = 1
        #expect(result == expected)
    }
}
