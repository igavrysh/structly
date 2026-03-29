//
//  InsertNodeTests.swift
//  MyCLI
//
//  Created by new on 3/22/26.
//

import Testing
@testable import structy

@Suite("04_InsertNodeTests")
struct InsertNodeTests {
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
            insertNode(a, "x", 2)
        }
        let values = linkedListValues(result)
        #expect(values == ["a", "b", "x", "c", "d"])
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
            insertNode(a, "v", 3)
        }
        let values = linkedListValues(result)
        #expect(values == ["a", "b", "c", "v", "d"])
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
            insertNode(a, "m", 4)
        }
        let values = linkedListValues(result)
        #expect(values == ["a", "b", "c", "d", "m"])
    }

    @Test("test_03")
    func test03() async throws {
        let a = Node("a")
        let b = Node("b")

        a.next = b

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            insertNode(a, "z", 0)
        }
        let values = linkedListValues(result)
        #expect(values == ["z", "a", "b"])
    }

    @Test("test_04")
    func test04() async throws {
        let a: Node<String>? = nil
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            insertNode(a, "foobar", 0)
        }
        let values = linkedListValues(result)
        #expect(values == ["foobar"])
    }
}
