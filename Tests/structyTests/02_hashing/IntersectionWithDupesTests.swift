//
//  IntersectionWithDupesTests.swift
//  MyCLI
//
//  Created by new on 3/13/26.
//

import Testing
@testable import structy
@Suite
final class IntersectionWithDupesTests {
    @Test
    func test00() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            intersectionWithDupes(["a", "b", "c", "b"], ["x", "y", "b", "b"])
        }
        #expect(result.sorted() == ["b", "b"].sorted())
    }

    @Test
    func test01() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            intersectionWithDupes(["q", "b", "m", "s", "s", "s"], ["s", "m", "s"])
        }
        #expect(result.sorted() == ["m", "s", "s"].sorted())
    }

    @Test
    func test02() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            intersectionWithDupes(["p", "r", "r", "r"], ["r"])
        }
        #expect(result.sorted() == ["r"].sorted())
    }

    @Test
    func test03() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            intersectionWithDupes(["r"], ["p", "r", "r", "r"])
        }
        #expect(result.sorted() == ["r"].sorted())
    }

    @Test
    func test04() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            intersectionWithDupes(["t", "v", "u"], ["g", "e", "d", "f"])
        }
        #expect(result.sorted() == [])
    }

    @Test
    func test05() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            intersectionWithDupes(["a", "a", "a", "a", "a", "a"], ["a", "a", "a", "a"])
        }
        #expect(result.sorted() == ["a", "a", "a", "a"].sorted())
    }

    @Test
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
