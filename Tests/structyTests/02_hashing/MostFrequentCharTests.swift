//
//  MostFrequentChar.swift
//  MyCLI
//
//  Created by new on 3/10/26.
//

import Testing
@testable import structy
@Suite
final class MostFrequentCharTests {
    @Test
    func test00() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mostFrequentChar("bookeeper")
        }
        #expect(result == "e")
    }

    @Test
    func test01() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mostFrequentChar("david")
        }
        #expect(result == "d")
    }

    @Test
    func test02() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mostFrequentChar("abby")
        }
        #expect(result == "b")
    }

    @Test
    func test03() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mostFrequentChar("mississippi")
        }
        #expect(result == "i")
    }

    @Test
    func test04() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mostFrequentChar("potato")
        }
        #expect(result == "o")
    }

    @Test
    func test05() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mostFrequentChar("eleventennine")
        }
        #expect(result == "e")
    }

    @Test
    func test06() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            mostFrequentChar("riverbed")
        }
        #expect(result == "r")
    }
}
