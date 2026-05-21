//
//  ReverseList.swift
//  MyCLI
//
//  Created by new on 3/18/26.
//

import Testing
@testable import structy
@Suite
final class ReverseListTests {
    @Test
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
            reverseList(a)
        }
        let values = linkedListValues(result)
        #expect(values == ["f", "e", "d", "c", "b", "a"])
    }

    @Test
    func test01() async throws {
        let x = Node("x")
        let y = Node("y")

        x.next = y

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            reverseList(x)
        }
        let values = linkedListValues(result)
        #expect(values == ["y", "x"])
    }

    @Test
    func test02() async throws {
        let p = Node("p")

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            reverseList(p)
        }
        let values = linkedListValues(result)
        #expect(values == ["p"])
    }

    @Test
    func test03() async throws {
        let p: Node<String>? = nil

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            reverseList(p)
        }
        let values = linkedListValues(result)
        #expect(values == [])
    }
}
