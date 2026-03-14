//
//  SumOfLengthsTests.swift
//  MyCLI
//
//  Created by new on 3/14/26.
//

import Testing
@testable import structly

struct SumOfLengthsTests {
    @Test("test_00")
    func test00() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            sum_of_lengths(["goat", "cat", "purple"])
        }
        #expect(result == 13)
    }

    @Test("test_01")
    func test01() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            sum_of_lengths(["bike", "at", "pencils", "phone"])
        }
        #expect(result == 18)
    }

    @Test("test_02")
    func test02() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            sum_of_lengths([])
        }
        #expect(result == 0)
    }

    @Test("test_03")
    func test03() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            sum_of_lengths(["", " ", "  ", "   ", "    ", "     "])
        }
        #expect(result == 15)
    }

    @Test("test_04")
    func test04() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            sum_of_lengths(["0", "313", "1234567890"])
        }
        #expect(result == 14)
    }
}
