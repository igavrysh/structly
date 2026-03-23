//
//  LinkedListFindTests.swift
//  MyCLI
//
//  Created by new on 3/16/26.
//

import Testing
@testable import structly

@Suite("04_LinkedListFindTests")
struct LinkedListFindTests {
    @Test("test_00")
    func test00() async throws {
        let a = Node("a")
        let b = Node("b")
        let c = Node("c")
        let d = Node("d")

        a.next = b
        b.next = c
        c.next = d

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            linkedListFind(a, "c")
        }
        #expect(result == true)
    }

    @Test("test_01")
    func test01() async throws {
        let a = Node("a")
        let b = Node("b")
        let c = Node("c")
        let d = Node("d")

        a.next = b
        b.next = c
        c.next = d

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            linkedListFind(a, "d")
        }
        #expect(result == true)
    }

    @Test("test_02")
    func test02() async throws {
        let a = Node("a")
        let b = Node("b")
        let c = Node("c")
        let d = Node("d")

        a.next = b
        b.next = c
        c.next = d

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            linkedListFind(a, "q")
        }
        #expect(result == false)
    }

    @Test("test_03")
    func test03() async throws {
        let node1 = Node("jason")
        let node2 = Node("leneli")

        node1.next = node2

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            linkedListFind(node1, "jason")
        }
        #expect(result == true)
    }

    @Test("test_04")
    func test04() async throws {
        let node1 = Node(42)

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            linkedListFind(node1, 42)
        }
        #expect(result == true)
    }

    @Test("test_05")
    func test05() async throws {
        let node1 = Node(42)

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            linkedListFind(node1, 100)
        }
        #expect(result == false)
    }
}
