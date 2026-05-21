//
//  LargestComponentTests.swift
//  MyCLI
//
//  Created by new on 3/30/26.
//

import Testing

@testable import structy
@Suite
final class LargestComponentTests {
    @Test
    func test00() {
        let graph: [Int: [Int]] = [
            0: [8, 1, 5],
            1: [0],
            5: [0, 8],
            8: [0, 5],
            2: [3, 4],
            3: [2, 4],
            4: [3, 2]
        ]
        let result = largestComponent(graph)
        #expect(result == 4)
    }

    @Test

    func test01() {
        let graph: [Int: [Int]] = [
            1: [2],
            2: [1, 8],
            6: [7],
            9: [8],
            7: [6, 8],
            8: [9, 7, 2]
        ]
        let result = largestComponent(graph)
        #expect(result == 6)
    }

    @Test

    func test02() {
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
        let result = largestComponent(graph)
        #expect(result == 5)
    }

    @Test

    func test03() {
        let graph: [Int: [Int]] = [:]
        let result = largestComponent(graph)
        #expect(result == 0)
    }

    @Test

    func test04() {
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
        let result = largestComponent(graph)
        #expect(result == 3)
    }
}
