//
//  IntersectionWithDupesTests.swift
//  MyCLI
//
//  Created by new on 3/13/26.
//

import Testing
@testable import structly

struct IntersectionWithDupesTests {
    @Test("test_00")
    func test00() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            intersectionWithDupes(["a", "b", "c", "b"], ["x", "y", "b", "b"])
        }
        #expect(result.sorted() == ["b", "b"].sorted())
    }

    @Test("test_01")
    func test01() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            intersectionWithDupes(["q", "b", "m", "s", "s", "s"], ["s", "m", "s"])
        }
        #expect(result.sorted() == ["m", "s", "s"].sorted())
    }

    @Test("test_02")
    func test02() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            intersectionWithDupes(["p", "r", "r", "r"], ["r"])
        }
        #expect(result.sorted() == ["r"].sorted())
    }

    @Test("test_03")
    func test03() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            intersectionWithDupes(["r"], ["p", "r", "r", "r"])
        }
        #expect(result.sorted() == ["r"].sorted())
    }

    @Test("test_04")
    func test04() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            intersectionWithDupes(["t", "v", "u"], ["g", "e", "d", "f"])
        }
        #expect(result.sorted() == [])
    }

    @Test("test_05")
    func test05() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            intersectionWithDupes(["a", "a", "a", "a", "a", "a"], ["a", "a", "a", "a"])
        }
        #expect(result.sorted() == ["a", "a", "a", "a"].sorted())
    }

    @Test("test_06")
    func test06() async throws {
        let a = Array(0..<150000).map { String($0) }
        let b = Array(0..<150000).map { String($0) }
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            intersectionWithDupes(a, b)
        }
        let expected = Array(0..<150000).map { String($0) }
        #expect(result.sorted() == expected.sorted())
    }
}
