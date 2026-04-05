//
//  ShortestPath.swift
//  MyCLI
//
//  Created by new on 3/31/26.
//

import Testing
@testable import structy

@Suite("05 ShortestPathTests")
struct ShortestPathTests {
    @Test("test_00")
    func test00() async throws {
        let edges = [
            ["w", "x"],
            ["x", "y"],
            ["z", "y"],
            ["z", "v"],
            ["w", "v"]
        ]

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            shortestPath(edges, "w", "z")
        }
        #expect(result == 2)
    }

    @Test("test_01")
    func test01() async throws {
        let edges = [
            ["w", "x"],
            ["x", "y"],
            ["z", "y"],
            ["z", "v"],
            ["w", "v"]
        ]

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            shortestPath(edges, "y", "x")
        }
        #expect(result == 1)
    }

    @Test("test_02")
    func test02() async throws {
        let edges = [
            ["a", "c"],
            ["a", "b"],
            ["c", "b"],
            ["c", "d"],
            ["b", "d"],
            ["e", "d"],
            ["g", "f"]
        ]

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            shortestPath(edges, "a", "e")
        }
        #expect(result == 3)
    }

    @Test("test_03")
    func test03() async throws {
        let edges = [
            ["a", "c"],
            ["a", "b"],
            ["c", "b"],
            ["c", "d"],
            ["b", "d"],
            ["e", "d"],
            ["g", "f"]
        ]

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            shortestPath(edges, "e", "c")
        }
        #expect(result == 2)
    }

    //@Test("test_04")
    func test04() async throws {
        let edges = [
            ["a", "c"],
            ["a", "b"],
            ["c", "b"],
            ["c", "d"],
            ["b", "d"],
            ["e", "d"],
            ["g", "f"]
        ]

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            shortestPath(edges, "b", "g")
        }
        #expect(result == -1)
    }

    @Test("test_05")
    func test05() async throws {
        let edges = [
            ["c", "n"],
            ["c", "e"],
            ["c", "s"],
            ["c", "w"],
            ["w", "e"]
        ]

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            shortestPath(edges, "w", "e")
        }
        #expect(result == 1)
    }

    @Test("test_06")
    func test06() async throws {
        let edges = [
            ["c", "n"],
            ["c", "e"],
            ["c", "s"],
            ["c", "w"],
            ["w", "e"]
        ]

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            shortestPath(edges, "n", "e")
        }
        #expect(result == 2)
    }

    @Test("test_07")
    func test07() async throws {
        let edges = [
            ["m", "n"],
            ["n", "o"],
            ["o", "p"],
            ["p", "q"],
            ["t", "o"],
            ["r", "q"],
            ["r", "s"]
        ]

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            shortestPath(edges, "m", "s")
        }
        #expect(result == 6)
    }
}
