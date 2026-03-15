//
//  ExclusiveItemsTests.swift
//  MyCLI
//
//  Created by new on 3/12/26.
//

import Testing
@testable import structly

@Suite("02_ExclusiveItemsTests")
struct ExclusiveItemsTests {
    @Test("test_00")
    func test00() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            exclusiveItems([4, 2, 1, 6], [3, 6, 9, 2, 10])
        }
        #expect(Set<Int>(result) == Set<Int>([4, 1, 3, 9, 10]))
    }

    @Test("test_01")
    func test01() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            exclusiveItems([2, 4, 6], [4, 2])
        }
        #expect(Set<Int>(result) == Set<Int>([6]))
    }

    @Test("test_02")
    func test02() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            exclusiveItems([4, 2, 1], [1, 2, 4, 6])
        }
        #expect(Set<Int>(result) == Set<Int>([6]))
    }

    @Test("test_03")
    func test03() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            exclusiveItems([0, 1, 2], [10, 11])
        }
        #expect(Set<Int>(result) == Set<Int>([0, 1, 2, 10, 11]))
    }

    @Test("test_04")
    func test04() async throws {
        let a = Array(0..<50000)
        let b = Array(0..<50000)
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            exclusiveItems(a, b)
        }
        #expect(Set<Int>(result) == Set<Int>())
    }
}
