//
//  SumNumbersRecursiveTests.swift
//  MyCLI
//
//  Created by new on 3/14/26.
//

import Testing
@testable import structly

struct SumNumbersRecursiveTests {
    @Test("test_00")
    func test00() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            sumNumbersRecursive([5, 2, 9, 10])
        }
        #expect(result == 26)
    }

    @Test("test_01")
    func test01() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            sumNumbersRecursive([1, -1, 1, -1, 1, -1, 1])
        }
        #expect(result == 1)
    }

    @Test("test_02")
    func test02() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            sumNumbersRecursive([])
        }
        #expect(result == 0)
    }

    @Test("test_03")
    func test03() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            sumNumbersRecursive([1000, 0, 0, 0, 0, 0, 1])
        }
        #expect(result == 1001)
    }

    @Test("test_04")
    func test04() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            sumNumbersRecursive([700, 70, 7])
        }
        #expect(result == 777)
    }

    @Test("test_05")
    func test05() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            sumNumbersRecursive([-10, -9, -8, -7, -6, -5, -4, -3, -2, -1])
        }
        #expect(result == -55)
    }

    @Test("test_06")
    func test06() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            sumNumbersRecursive([0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0])
        }
        #expect(result == 0)
    }

    @Test("test_07")
    func test07() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            sumNumbersRecursive([123456789, 12345678, 1234567, 123456, 12345, 1234, 123, 12, 1, 0])
        }
        #expect(result == 137174205)
    }
}
