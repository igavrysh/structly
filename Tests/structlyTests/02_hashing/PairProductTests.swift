//
//  PairProductTests.swift
//  MyCLI
//
//  Created by new on 3/12/26.
//

import Testing
@testable import structly

struct PairProductTests {
    @Test("test_00")
    func test00() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            pairProduct([3, 2, 5, 4, 1], 8)
        }
        #expect(result.0 == 1)
        #expect(result.1 == 3)
    }

    @Test("test_01")
    func test01() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            pairProduct([3, 2, 5, 4, 1], 10)
        }
        #expect(result.0 == 1)
        #expect(result.1 == 2)
    }

    @Test("test_02")
    func test02() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            pairProduct([4, 7, 9, 2, 5, 1], 5)
        }
        #expect(result.0 == 4)
        #expect(result.1 == 5)
    }

    @Test("test_03")
    func test03() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            pairProduct([4, 7, 9, 2, 5, 1], 35)
        }
        #expect(result.0 == 1)
        #expect(result.1 == 4)
    }

    @Test("test_04")
    func test04() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            pairProduct([3, 2, 5, 4, 1], 10)
        }
        #expect(result.0 == 1)
        #expect(result.1 == 2)
    }

    @Test("test_05")
    func test05() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            pairProduct([4, 6, 8, 2], 16)
        }
        #expect(result.0 == 2)
        #expect(result.1 == 3)
    }

    @Test("test_06")
    func test06() async throws {
        let numbers = Array(0...21000)
        let result = try await TimeoutSupport.runWithTimeout(seconds: 4) {
            pairProduct(numbers, 440979000)
        }
        #expect(result.0 == 20999)
        #expect(result.1 == 21000)
    }
}

