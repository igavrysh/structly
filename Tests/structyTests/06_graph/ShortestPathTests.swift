//
//  ShortestPath.swift
//  MyCLI
//
//  Created by new on 3/31/26.
//

import Testing
@testable import structy
@Suite
final class ShortestPathTests {
    @Test
    func test00() {
        let edges = [
            ["w", "x"],
            ["x", "y"],
            ["z", "y"],
            ["z", "v"],
            ["w", "v"]
        ]
        let result = shortestPath(edges, "w", "z")
        #expect(result == 2)
    }

    @Test
    func test01() {
        let edges = [
            ["w", "x"],
            ["x", "y"],
            ["z", "y"],
            ["z", "v"],
            ["w", "v"]
        ]
        let result = shortestPath(edges, "y", "x")
        #expect(result == 1)
    }

    @Test
    func test02() {
        let edges = [
            ["a", "c"],
            ["a", "b"],
            ["c", "b"],
            ["c", "d"],
            ["b", "d"],
            ["e", "d"],
            ["g", "f"]
        ]
        let result = shortestPath(edges, "a", "e")
        #expect(result == 3)
    }

    @Test
    func test03() {
        let edges = [
            ["a", "c"],
            ["a", "b"],
            ["c", "b"],
            ["c", "d"],
            ["b", "d"],
            ["e", "d"],
            ["g", "f"]
        ]
        let result = shortestPath(edges, "e", "c")
        #expect(result == 2)
    }

    @Test
    func test04() {
        let edges = [
            ["a", "c"],
            ["a", "b"],
            ["c", "b"],
            ["c", "d"],
            ["b", "d"],
            ["e", "d"],
            ["g", "f"]
        ]
        let result = shortestPath(edges, "b", "g")
        #expect(result == -1)
    }

    @Test
    func test05() {
        let edges = [
            ["c", "n"],
            ["c", "e"],
            ["c", "s"],
            ["c", "w"],
            ["w", "e"]
        ]
        let result = shortestPath(edges, "w", "e")
        #expect(result == 1)
    }

    @Test

    func test06() {
        let edges = [
            ["c", "n"],
            ["c", "e"],
            ["c", "s"],
            ["c", "w"],
            ["w", "e"]
        ]
        let result = shortestPath(edges, "n", "e")
        #expect(result == 2)
    }

    @Test

    func test07() {
        let edges = [
            ["m", "n"],
            ["n", "o"],
            ["o", "p"],
            ["p", "q"],
            ["t", "o"],
            ["r", "q"],
            ["r", "s"]
        ]
        let result = shortestPath(edges, "m", "s")
        #expect(result == 6)
    }
}
