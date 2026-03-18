//
//  SumListTests.swift
//  MyCLI
//
//  Created by new on 3/16/26.
//

import Testing
@testable import structly

@Suite("04_SumListTests")
struct SumListTests {
    @Test("test_00")
    func test00() async throws {
        let a = Node(2)
        let b = Node(8)
        let c = Node(3)
        let d = Node(-1)
        let e = Node(7)

        a.next = b
        b.next = c
        c.next = d
        d.next = e

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            sumList(a)
        }
        #expect(result == 19)
    }

    @Test("test_01")
    func test01() async throws {
        let x = Node(38)
        let y = Node(4)

        x.next = y

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            sumList(x)
        }
        #expect(result == 42)
    }

    @Test("test_02")
    func test02() async throws {
        let z = Node(100)

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            sumList(z)
        }
        #expect(result == 100)
    }

    @Test("test_03")
    func test03() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            sumList(nil)
        }
        #expect(result == 0)
    }
}
