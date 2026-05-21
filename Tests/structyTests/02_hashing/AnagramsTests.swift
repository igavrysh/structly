//
//  longestWordTest.swift
//  MyCLI
//
//  Created by new on 3/10/26.
//

import Testing
@testable import structy
@Suite
final class AnagramsTests {
    @Test
    func test00() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("restful", "fluster")
        }
        #expect(result == true)
    }

    @Test
    func test01() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("cats", "tocs")
        }
        #expect(result == false)
    }

    @Test
    func test02() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("monkeyswrite", "newyorktimes")
        }
        #expect(result == true)
    }

    @Test
    func test03() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("paper", "reapa")
        }
        #expect(result == false)
    }

    @Test
    func test04() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("elbow", "below")
        }
        #expect(result == true)
    }

    @Test
    func test05() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("tax", "taxi")
        }
        #expect(result == false)
    }

    @Test
    func test06() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("taxi", "tax")
        }
        #expect(result == false)
    }

    @Test
    func test07() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("night", "thing")
        }
        #expect(result == true)
    }

    @Test
    func test08() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("abbc", "aabc")
        }
        #expect(result == false)
    }

    @Test
    func test09() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("po", "popp")
        }
        #expect(result == false)
    }

    @Test
    func test10() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            anagrams("pp", "oo")
        }
        #expect(result == false)
    }
}
