//
//  longestWordTest.swift
//  MyCLI
//
//  Created by new on 3/10/26.
//

import Testing
@testable import structly

@Suite
final class AnagramsTests {
    @Test("test_00")
    func test00() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("restful", "fluster")
        }
        #expect(result == true)
    }

    @Test("test_01")
    func test01() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("cats", "tocs")
        }
        #expect(result == false)
    }

    @Test("test_02")
    func test02() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("monkeyswrite", "newyorktimes")
        }
        #expect(result == true)
    }

    @Test("test_03")
    func test03() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("paper", "reapa")
        }
        #expect(result == false)
    }

    @Test("test_04")
    func test04() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("elbow", "below")
        }
        #expect(result == true)
    }

    @Test("test_05")
    func test05() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("tax", "taxi")
        }
        #expect(result == false)
    }

    @Test("test_06")
    func test06() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("taxi", "tax")
        }
        #expect(result == false)
    }

    @Test("test_07")
    func test07() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("night", "thing")
        }
        #expect(result == true)
    }

    @Test("test_08")
    func test08() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("abbc", "aabc")
        }
        #expect(result == false)
    }

    @Test("test_09")
    func test09() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("po", "popp")
        }
        #expect(result == false)
    }

    @Test("test_10")
    func test10() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("pp", "oo")
        }
        #expect(result == false)
    }
}
