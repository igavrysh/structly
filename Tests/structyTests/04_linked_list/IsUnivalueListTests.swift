//
//  IsUnivalueListTests.swift
//  MyCLI
//
//  Created by new on 3/22/26.
//

import Testing
@testable import structy

@Suite("04_IsUnivalueListTests")
struct IsUnivalueListTests {
    @Test("test_00")
    func test00() async throws {
        let a = Node(7)
        let b = Node(7)
        let c = Node(7)

        a.next = b
        b.next = c

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            isUnivalueList(a)
        }
        #expect(result == true)
    }

    @Test("test_01")
    func test01() async throws {
        let a = Node(7)
        let b = Node(7)
        let c = Node(4)

        a.next = b
        b.next = c

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            isUnivalueList(a)
        }
        #expect(result == false)
    }

    @Test("test_02")
    func test02() async throws {
        let u = Node(2)
        let v = Node(2)
        let w = Node(2)
        let x = Node(2)
        let y = Node(2)

        u.next = v
        v.next = w
        w.next = x
        x.next = y

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            isUnivalueList(u)
        }
        #expect(result == true)
    }

    @Test("test_03")
    func test03() async throws {
        let u = Node(2)
        let v = Node(2)
        let w = Node(3)
        let x = Node(3)
        let y = Node(2)

        u.next = v
        v.next = w
        w.next = x
        x.next = y

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            isUnivalueList(u)
        }
        #expect(result == false)
    }

    @Test("test_04")
    func test04() async throws {
        let z = Node("z")

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            isUnivalueList(z)
        }
        #expect(result == true)
    }

    @Test("test_05")
    func test05() async throws {
        let u = Node(2)
        let v = Node(1)
        let w = Node(2)
        let x = Node(2)
        let y = Node(2)

        u.next = v
        v.next = w
        w.next = x
        x.next = y

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            isUnivalueList(u)
        }
        #expect(result == false)
    }

    @Test("test_06")
    func test06() async throws {
        let u: Node<Int>? = nil
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            isUnivalueList(u)
        }
        #expect(result == true)
    }
}
