//
//  ReverseStringRecursiveTests.swift
//  MyCLI
//
//  Created by new on 3/14/26.
//

import Testing
@testable import structy
@Suite
final class ReverseStringTests {
    @Test
    func test00() {
        let result = reverseString("hello")
        #expect(result == "olleh")
    }

    @Test
    func test01() {
        let result = reverseString("abcdefg")
        #expect(result == "gfedcba")
    }

    @Test
    func test02() {
        let result = reverseString("stopwatch")
        #expect(result == "hctawpots")
    }

    @Test
    func test03() {
        let result = reverseString("")
        #expect(result == "")
    }

    @Test
    func test10() {
        var s = "hello"
        let result = reverseStringOlolo(&s)
        #expect(result == "olleh")
    }

    @Test
    func test11() {
        var s = "abcdefg"
        let result = reverseStringOlolo(&s)
        #expect(result == "gfedcba")
    }

    @Test
    func test12() {
        var s = "stopwatch"
        let result = reverseStringOlolo(&s)
        #expect(result == "hctawpots")
    }

    @Test
    func test13() {
        let result = reverseString("")
        #expect(result == "")
    }
}
