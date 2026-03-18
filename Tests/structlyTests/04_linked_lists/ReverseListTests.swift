//
//  ReverseList.swift
//  MyCLI
//
//  Created by new on 3/18/26.
//

import Testing
@testable import structly

@Suite("04_ReverseListTests")
struct ReverseListTests {
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
            reverseList(a)
        }
        let values = linkedListValues(result)
        #expect(values == ["f", "e", "d", "c", "b", "a"])
    }

    @Test("test_01")
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

    @Test("test_02")
    func test02() async throws {
        let p = Node("p")

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            reverseList(p)
        }
        let values = linkedListValues(result)
        #expect(values == ["p"])
    }

    @Test("test_03")
    func test03() async throws {
        let p: Node<String>? = nil

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            reverseList(p)
        }
        let values = linkedListValues(result)
        #expect(values == [])
    }
}
