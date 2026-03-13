//
//  IntersectionTests.swift
//  MyCLI
//
//  Created by new on 3/12/26.
//

import Testing
@testable import structly

struct IntersectionTests {
    @Test("test_00")
    func test00() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            intersection([4, 2, 1, 6], [3, 6, 9, 2, 10])
        }
        #expect(Set<Int>(result) == Set<Int>([2, 6]))
    }

    @Test("test_01")
    func test01() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            intersection([2, 4, 6], [4, 2])
        }
        #expect(Set<Int>(result) == Set<Int>([2, 4]))
    }

    @Test("test_02")
    func test02() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            intersection([4, 2, 1], [1, 2, 4, 6])
        }
        #expect(Set<Int>(result) == Set<Int>([1, 2, 4]))
    }

    @Test("test_03")
    func test03() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            intersection([0, 1, 2], [10, 11])
        }
        #expect(Set<Int>(result) == Set<Int>())
    }

    @Test("test_04")
    func test04() async throws {
        let a = Array(0..<50000)
        let b = Array(0..<50000)
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            intersection(a, b)
        }
        let expected = Array(0..<50000)
        #expect(Set<Int>(result) == Set<Int>(expected))
    }
}
