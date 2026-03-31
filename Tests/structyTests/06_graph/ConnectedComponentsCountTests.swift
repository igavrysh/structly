//
//  ConnectedComponentsCountTests.swift
//  MyCLI
//
//  Created by new on 3/30/26.
//

import Testing
@testable import structy

@Suite("05 ConnectedComponentsCountTests")
struct ConnectedComponentsCountTests {
    @Test("test_00")
    func test00() async throws {
        let graph: [Int: [Int]] = [
            0: [8, 1, 5],
            1: [0],
            5: [0, 8],
            8: [0, 5],
            2: [3, 4],
            3: [2, 4],
            4: [3, 2]
        ]

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            connectedComponentsCount(graph)
        }
        #expect(result == 2)
    }

    @Test("test_01")
    func test01() async throws {
        let graph: [Int: [Int]] = [
            1: [2],
            2: [1, 8],
            6: [7],
            9: [8],
            7: [6, 8],
            8: [9, 7, 2]
        ]

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            connectedComponentsCount(graph)
        }
        #expect(result == 1)
    }

    @Test("test_02")
    func test02() async throws {
        let graph: [Int: [Int]] = [
            3: [],
            4: [6],
            6: [4, 5, 7, 8],
            8: [6],
            7: [6],
            5: [6],
            1: [2],
            2: [1]
        ]

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            connectedComponentsCount(graph)
        }
        #expect(result == 3)
    }

    @Test("test_03")
    func test03() async throws {
        let graph: [Int: [Int]] = [:]

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            connectedComponentsCount(graph)
        }
        #expect(result == 0)
    }

    @Test("test_04")
    func test04() async throws {
        let graph: [Int: [Int]] = [
            0: [4, 7],
            1: [],
            2: [],
            3: [6],
            4: [0],
            6: [3],
            7: [0],
            8: []
        ]

        let result = try await TimeoutSupport.runWithTimeout(seconds: 2) {
            connectedComponentsCount(graph)
        }
        #expect(result == 5)
    }
}
