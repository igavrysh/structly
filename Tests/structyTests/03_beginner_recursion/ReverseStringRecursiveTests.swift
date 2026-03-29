//
//  ReverseStringRecursiveTests.swift
//  MyCLI
//
//  Created by new on 3/14/26.
//

import Testing
@testable import structy

@Suite("03_ReverseStringTests")
struct ReverseStringTests {
    @Test("test_00")
    func test00() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            reverseString("hello")
        }
        #expect(result == "olleh")
    }

    @Test("test_01")
    func test01() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            reverseString("abcdefg")
        }
        #expect(result == "gfedcba")
    }

    @Test("test_02")
    func test02() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            reverseString("stopwatch")
        }
        #expect(result == "hctawpots")
    }

    @Test("test_03")
    func test03() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            reverseString("")
        }
        #expect(result == "")
    }


    @Test("test_10")
    func test10() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            var s = "hello"
            return reverseStringOlolo(&s)
        }
        #expect(result == "olleh")
    }

    @Test("test_11")
    func test11() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            var s = "abcdefg"
            return reverseStringOlolo(&s)
        }
        #expect(result == "gfedcba")
    }

    @Test("test_12")
    func test12() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            var s = "stopwatch"
            return reverseStringOlolo(&s)
        }
        #expect(result == "hctawpots")
    }

    @Test("test_13")
    func test13() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            let s = ""
            return reverseString(s)
        }
        #expect(result == "")
    }
}
