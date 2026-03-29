//
//  ZipperListsTests.swift
//  MyCLI
//
//  Created by new on 3/19/26.
//

import Testing
@testable import structy

@Suite("04_ZipperListsTests")
struct ZipperListsTests {
    @Test("test_00")
    func test00() async throws {
        let a = Node("a")
        let b = Node("b")
        let c = Node("c")
        a.next = b
        b.next = c

        let x = Node("x")
        let y = Node("y")
        let z = Node("z")
        x.next = y
        y.next = z

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            zipperLists(a, x)
        }
        let values = linkedListValues(result)
        #expect(values == ["a", "x", "b", "y", "c", "z"])
    }

    @Test("test_01")
    func test01() async throws {
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

        let x = Node("x")
        let y = Node("y")
        let z = Node("z")
        x.next = y
        y.next = z

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            zipperLists(a, x)
        }
        let values = linkedListValues(result)
        #expect(values == ["a", "x", "b", "y", "c", "z", "d", "e", "f"])
    }

    @Test("test_02")
    func test02() async throws {
        let s = Node("s")
        let t = Node("t")
        s.next = t

        let one = Node("1")
        let two = Node("2")
        let three = Node("3")
        let four = Node("4")
        one.next = two
        two.next = three
        three.next = four

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            zipperLists(s, one)
        }
        let values = linkedListValues(result)
        #expect(values == ["s", "1", "t", "2", "3", "4"])
    }

    @Test("test_03")
    func test03() async throws {
        let w = Node("w")

        let one = Node("1")
        let two = Node("2")
        let three = Node("3")
        one.next = two
        two.next = three

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            zipperLists(w, one)
        }
        let values = linkedListValues(result)
        #expect(values == ["w", "1", "2", "3"])
    }

    @Test("test_04")
    func test04() async throws {
        let one = Node("1")
        let two = Node("2")
        let three = Node("3")
        one.next = two
        two.next = three

        let w = Node("w")

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            zipperLists(one, w)
        }
        let values = linkedListValues(result)
        #expect(values == ["1", "w", "2", "3"])
    }

    @Test("test_05")
    func test05() async throws {
        let one: Node<String>? = nil
        let two = Node("2")

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            zipperLists(one, two)
        }
        let values = linkedListValues(result)
        #expect(values == ["2"])
    }

    @Test("test_06")
    func test06() async throws {
        let one = Node("1")
        let two: Node<String>? = nil

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            zipperLists(one, two)
        }
        let values = linkedListValues(result)
        #expect(values == ["1"])
    }

    @Test("test_07")
    func test07() async throws {
        let one: Node<String>? = nil
        let two: Node<String>? = nil

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            zipperLists(one, two)
        }
        let values = linkedListValues(result)
        #expect(values == [])
    }
}
