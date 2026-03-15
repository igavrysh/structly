//
//  AllUniqueTests.swift
//  MyCLI
//
//  Created by new on 3/13/26.
//

import Testing
@testable import structly

@Suite("02_AllUniqueTests")
struct AllUniqueTests {
    @Test("test_00")
    func test00() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            allUnique(["q", "r", "s", "a"])
        }
        #expect(result == true)
    }

    @Test("test_01")
    func test01() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            allUnique(["q", "r", "s", "a", "r", "z"])
        }
        #expect(result == false)
    }

    @Test("test_02")
    func test02() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            allUnique(["red", "blue", "yellow", "green", "orange"])
        }
        #expect(result == true)
    }

    @Test("test_03")
    func test03() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            allUnique(["cat", "cat", "dog"])
        }
        #expect(result == false)
    }

    @Test("test_04")
    func test04() async throws {
        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            allUnique(["a", "u", "t", "u", "m", "n"])
        }
        #expect(result == false)
    }
}
