//
//  LongestStreakTests.swift
//  MyCLI
//
//  Created by new on 3/22/26.
//

import Testing
@testable import structy
@Suite
final class LongestStreakTests {
    @Test
    func test00() async throws {
        let a = Node(5)
        let b = Node(5)
        let c = Node(7)
        let d = Node(7)
        let e = Node(7)
        let f = Node(6)

        a.next = b
        b.next = c
        c.next = d
        d.next = e
        e.next = f

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            longestStreak(a)
        }
        #expect(result == 3)
    }

    @Test
    func test01() async throws {
        let a = Node(3)
        let b = Node(3)
        let c = Node(3)
        let d = Node(3)
        let e = Node(9)
        let f = Node(9)

        a.next = b
        b.next = c
        c.next = d
        d.next = e
        e.next = f

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            longestStreak(a)
        }
        #expect(result == 4)
    }

    @Test
    func test02() async throws {
        let a = Node(9)
        let b = Node(9)
        let c = Node(1)
        let d = Node(9)
        let e = Node(9)
        let f = Node(9)

        a.next = b
        b.next = c
        c.next = d
        d.next = e
        e.next = f

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            longestStreak(a)
        }
        #expect(result == 3)
    }

    @Test
    func test03() async throws {
        let a = Node(5)
        let b = Node(5)

        a.next = b

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            longestStreak(a)
        }
        #expect(result == 2)
    }

    @Test
    func test04() async throws {
        let a = Node(4)

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            longestStreak(a)
        }
        #expect(result == 1)
    }

    @Test
    func test05() async throws {
        let result: Int = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            longestStreak(nil as Node<Int>?)
        }
        #expect(result == 0)
    }
}
