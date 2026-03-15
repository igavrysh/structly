//
//  FibonacciTests.swift
//  MyCLI
//
//  Created by new on 3/15/26.
//

import Testing
@testable import structly

struct FibonacciTests {
    @Test("test_00")
    func test00() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            fibonacci(0)
        }
        #expect(result == 0)
    }

    @Test("test_01")
    func test01() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            fibonacci(1)
        }
        #expect(result == 1)
    }

    @Test("test_02")
    func test02() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            fibonacci(2)
        }
        #expect(result == 1)
    }

    @Test("test_03")
    func test03() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            fibonacci(3)
        }
        #expect(result == 2)
    }

    @Test("test_04")
    func test04() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            fibonacci(4)
        }
        #expect(result == 3)
    }

    @Test("test_05")
    func test05() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            fibonacci(5)
        }
        #expect(result == 5)
    }

    @Test("test_06")
    func test06() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            fibonacci(8)
        }
        #expect(result == 21)
    }
}
