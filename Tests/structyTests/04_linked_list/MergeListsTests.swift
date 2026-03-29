//
//  MergeListsTests.swift
//  MyCLI
//
//  Created by new on 3/21/26.
//

import Testing
@testable import structy

@Suite("04_MergeListsTests")
struct MergeListsTests {
    @Test("test_00")
    func test00() async throws {
        let a = Node(5)
        let b = Node(7)
        let c = Node(10)
        let d = Node(12)
        let e = Node(20)
        let f = Node(28)
        a.next = b
        b.next = c
        c.next = d
        d.next = e
        e.next = f

        let q = Node(6)
        let r = Node(8)
        let s = Node(9)
        let t = Node(25)
        q.next = r
        r.next = s
        s.next = t

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mergeLists(a, q)
        }
        let values = linkedListValues(result)
        #expect(values == [5, 6, 7, 8, 9, 10, 12, 20, 25, 28])
    }

    @Test("test_01")
    func test01() async throws {
        let a = Node(5)
        let b = Node(7)
        let c = Node(10)
        let d = Node(12)
        let e = Node(20)
        let f = Node(28)
        a.next = b
        b.next = c
        c.next = d
        d.next = e
        e.next = f

        let q = Node(1)
        let r = Node(8)
        let s = Node(9)
        let t = Node(10)
        q.next = r
        r.next = s
        s.next = t

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mergeLists(a, q)
        }
        let values = linkedListValues(result)
        #expect(values == [1, 5, 7, 8, 9, 10, 10, 12, 20, 28])
    }

    @Test("test_02")
    func test02() async throws {
        let h = Node(30)

        let p = Node(15)
        let q = Node(67)
        p.next = q

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mergeLists(h, p)
        }
        let values = linkedListValues(result)
        #expect(values == [15, 30, 67])
    }

    @Test("test_03")
    func test03() async throws {
        let p = Node(15)
        let q = Node(67)
        p.next = q

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mergeLists(p, nil)
        }
        let values = linkedListValues(result)
        #expect(values == [15, 67])
    }

    @Test("test_04")
    func test04() async throws {
        let p = Node(15)
        let q = Node(67)
        p.next = q

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mergeLists(nil, p)
        }
        let values = linkedListValues(result)
        #expect(values == [15, 67])
    }

    @Test("test_05")
    func test05() async throws {
        let one: Node<Int>? = nil
        let two = Node(2)

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mergeLists(one, two)
        }
        let values = linkedListValues(result)
        #expect(values == [2])
    }

    @Test("test_06")
    func test06() async throws {
        let one = Node(1)
        let two: Node<Int>? = nil

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mergeLists(one, two)
        }
        let values = linkedListValues(result)
        #expect(values == [1])
    }

    @Test("test_07")
    func test07() async throws {
        let one: Node<Int>? = nil
        let two: Node<Int>? = nil

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mergeLists(one, two)
        }
        let values = linkedListValues(result)
        #expect(values == [])
    }
}
