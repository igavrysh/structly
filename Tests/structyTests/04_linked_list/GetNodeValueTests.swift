//
//  GetNodeValueTests.swift
//  MyCLI
//
//  Created by new on 3/18/26.
//

import Testing
@testable import structy
@Suite
final class GetNodeValueTests {
    @Test
    func test00() async throws {
        let a = Node("a")
        let b = Node("b")
        let c = Node("c")
        let d = Node("d")

        a.next = b
        b.next = c
        c.next = d

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            getNodeValue(a, 2)
        }
        #expect(result == "c")
    }

    @Test
    func test01() async throws {
        let a = Node("a")
        let b = Node("b")
        let c = Node("c")
        let d = Node("d")

        a.next = b
        b.next = c
        c.next = d

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            getNodeValue(a, 3)
        }
        #expect(result == "d")
    }

    @Test
    func test02() async throws {
        let a = Node("a")
        let b = Node("b")
        let c = Node("c")
        let d = Node("d")

        a.next = b
        b.next = c
        c.next = d

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            getNodeValue(a, 7)
        }
        #expect(result == "")
    }

    @Test
    func test03() async throws {
        let node1 = Node("banana")
        let node2 = Node("mango")

        node1.next = node2

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            getNodeValue(node1, 0)
        }
        #expect(result == "banana")
    }

    @Test
    func test04() async throws {
        let node1 = Node("banana")
        let node2 = Node("mango")

        node1.next = node2

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            getNodeValue(node1, 1)
        }
        #expect(result == "mango")
    }
}
