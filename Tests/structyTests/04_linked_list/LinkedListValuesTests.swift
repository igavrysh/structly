//
//  linkedListValues.swift
//  MyCLI
//
//  Created by new on 3/15/26.
//

import Testing
@testable import structy

@Suite("04_LinkedListValuesTests")
struct LinkedListValuesTests {
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
            linkedListValues(a)
        }
        #expect(result == ["a", "b", "c", "d"])
    }

    @Test("test_01")
    func test01() async throws {
        let x = Node("x")
        let y = Node("y")

        x.next = y

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            linkedListValues(x)
        }
        #expect(result == ["x", "y"])
    }

    @Test("test_02")
    func test02() async throws {
        let q = Node("q")

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            linkedListValues(q)
        }
        #expect(result == ["q"])
    }

    @Test("test_03")
    func test03() async throws {
        let result: [String] = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            linkedListValues(nil)
        }
        #expect(result == [])
    }
}
