//
//  PalindromeTests.swift
//  MyCLI
//
//  Created by new on 3/14/26.
//

import Testing
@testable import structly

struct PalindromeTests {
    @Test("test_00")
    func test00() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            palindrome("pop")
        }
        print("result: \(result)")
        #expect(result == true)
    }

    @Test("test_01")
    func test01() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            palindrome("kayak")
        }
        #expect(result == true)
    }

    @Test("test_02")
    func test02() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            palindrome("pops")
        }
        #expect(result == false)
    }

    @Test("test_03")
    func test03() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            palindrome("boot")
        }
        #expect(result == false)
    }

    @Test("test_04")
    func test04() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            palindrome("rotator")
        }
        #expect(result == true)
    }

    @Test("test_05")
    func test05() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            palindrome("abcbca")
        }
        #expect(result == false)
    }

    @Test("test_06")
    func test06() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            palindrome("")
        }
        #expect(result == true)
    }

    @Test("test_ololo")
    func test_ololo() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            palindrome("👨‍👩‍👧‍👦􀫊👨‍👩‍👧‍👦")
        }
        #expect(result == true)
    }

    @Test("test_ololo2")
    func test_ololo2() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            palindrome("􀥺􀪯􁎖")
        }
        #expect(result == false)
    }
}
