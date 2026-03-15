//
//  ReverseStringRecursiveTests.swift
//  MyCLI
//
//  Created by new on 3/14/26.
//

import Testing
@testable import structly

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
}
