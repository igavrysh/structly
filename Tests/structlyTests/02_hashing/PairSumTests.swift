//
//  PairSumTest.swift
//  MyCLI
//
//  Created by new on 3/12/26.
//

import Testing
@testable import structly

@Suite("02_PairSumTests")
struct PairSumTests {
    @Test("test_00")
    func test00() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            pairSum([3, 2, 5, 4, 1], 8)
        }
        #expect(result.0 == 0)
        #expect(result.1 == 2)
    }

    @Test("test_01")
    func test01() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            pairSum([4, 7, 9, 2, 5, 1], 5)
        }
        #expect(result.0 == 0)
        #expect(result.1 == 5)
    }

    @Test("test_02")
    func test02() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            pairSum([4, 7, 9, 2, 5, 1], 3)
        }
        #expect(result.0 == 3)
        #expect(result.1 == 5)
    }

    @Test("test_03")
    func test03() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            pairSum([1, 6, 7, 2], 13)
        }
        #expect(result.0 == 1)
        #expect(result.1 == 2)
    }

    @Test("test_04")
    func test04() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            pairSum([9, 9], 18)
        }
        #expect(result.0 == 0)
        #expect(result.1 == 1)
    }

    @Test("test_05")
    func test05() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            pairSum([6, 4, 2, 8], 12)
        }
        #expect(result.0 == 1)
        #expect(result.1 == 3)
    }

    @Test("test_06")
    func test06() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            pairSum([5, 4, 1, 4], 8)
        }
        #expect(result.0 == 1)
        #expect(result.1 == 3)
    }

    @Test("test_07")
    func test07() async throws {
        let numbers = Array(1...6000)
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            pairSum(numbers, 11999)
        }
        #expect(result.0 == 5998)
        #expect(result.1 == 5999)
    }
}

