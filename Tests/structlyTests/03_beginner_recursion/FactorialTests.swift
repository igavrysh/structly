//
//  Factorial.swift
//  MyCLI
//
//  Created by new on 3/14/26.
//

import Testing
@testable import structly

@Suite("03_FactorialTests")
struct FactorialTests {
    @Test("test_00")
    func test00() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            factorial(3)
        }
        #expect(result == 6)
    }

    @Test("test_01")
    func test01() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            factorial(6)
        }
        #expect(result == 720)
    }

    @Test("test_02")
    func test02() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            factorial(18)
        }
        #expect(result == 6402373705728000)
    }

    @Test("test_03")
    func test03() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            factorial(1)
        }
        #expect(result == 1)
    }

    @Test("test_04")
    func test04() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            factorial(13)
        }
        #expect(result == 6227020800)
    }

    @Test("test_05")
    func test05() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            factorial(0)
        }
        #expect(result == 1)
    }
}
