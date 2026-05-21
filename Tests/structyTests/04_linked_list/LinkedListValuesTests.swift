//
//  linkedListValues.swift
//  MyCLI
//
//  Created by new on 3/15/26.
//

import Testing
@testable import structy
@Suite
final class LinkedListValuesTests {
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
            linkedListValues(a)
        }
        #expect(result == ["a", "b", "c", "d"])
    }

    @Test
    func test01() async throws {
        let x = Node("x")
        let y = Node("y")

        x.next = y

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            linkedListValues(x)
        }
        #expect(result == ["x", "y"])
    }

    @Test
    func test02() async throws {
        let q = Node("q")

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            linkedListValues(q)
        }
        #expect(result == ["q"])
    }

    @Test
    func test03() async throws {
        let result: [String] = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            linkedListValues(nil)
        }
        #expect(result == [])
    }
}
