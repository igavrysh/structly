//
//  MostFrequentChar.swift
//  MyCLI
//
//  Created by new on 3/10/26.
//

import Testing
@testable import structly

@Suite("02_MostFrequentCharTests")
final class MostFrequentCharTests {
    @Test("test_00")
    func test00() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mostFrequentChar("bookeeper")
        }
        #expect(result == "e")
    }

    @Test("test_01")
    func test01() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mostFrequentChar("david")
        }
        #expect(result == "d")
    }

    @Test("test_02")
    func test02() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mostFrequentChar("abby")
        }
        #expect(result == "b")
    }

    @Test("test_03")
    func test03() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mostFrequentChar("mississippi")
        }
        #expect(result == "i")
    }

    @Test("test_04")
    func test04() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mostFrequentChar("potato")
        }
        #expect(result == "o")
    }

    @Test("test_05")
    func test05() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mostFrequentChar("eleventennine")
        }
        #expect(result == "e")
    }

    @Test("test_06")
    func test06() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mostFrequentChar("riverbed")
        }
        #expect(result == "r")
    }
}
