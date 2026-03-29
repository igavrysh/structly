//
//  RemoveNodeTests.swift
//  MyCLI
//
//  Created by new on 3/22/26.
//

import Testing
@testable import structy

@Suite("04_RemoveNodeTests")
struct RemoveNodeTests {
    @Test("test_00")
    func test00() async throws {
        let a = Node("a")
        let b = Node("b")
        let c = Node("c")
        let d = Node("d")
        let e = Node("e")
        let f = Node("f")

        a.next = b
        b.next = c
        c.next = d
        d.next = e
        e.next = f

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            removeNode(a, "c")
        }
        let values = linkedListValues(result)
        #expect(values == ["a", "b", "d", "e", "f"])
    }

    @Test("test_01")
    func test01() async throws {
        let x = Node("x")
        let y = Node("y")
        let z = Node("z")

        x.next = y
        y.next = z

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            removeNode(x, "z")
        }
        let values = linkedListValues(result)
        #expect(values == ["x", "y"])
    }

    @Test("test_02")
    func test02() async throws {
        let q = Node("q")
        let r = Node("r")
        let s = Node("s")

        q.next = r
        r.next = s

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            removeNode(q, "q")
        }
        let values = linkedListValues(result)
        #expect(values == ["r", "s"])
    }

    @Test("test_03")
    func test03() async throws {
        let node1 = Node("h")
        let node2 = Node("i")
        let node3 = Node("j")
        let node4 = Node("i")

        node1.next = node2
        node2.next = node3
        node3.next = node4

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            removeNode(node1, "i")
        }
        let values = linkedListValues(result)
        #expect(values == ["h", "j", "i"])
    }

    @Test("test_04")
    func test04() async throws {
        let node1 = Node("h")

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            removeNode(node1, "h")
        }
        let values = linkedListValues(result)
        #expect(values == [])
    }
}
