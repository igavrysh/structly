//
//  FibonacciTests.swift
//  MyCLI
//
//  Created by new on 3/15/26.
//

import Testing
@testable import structy
@Suite
final class FibonacciTests {
    @Test
    func test00() {
        let result = fibonacci(0)
        #expect(result == 0)
    }

    @Test
    func test01() {
        let result = fibonacci(1)
        #expect(result == 1)
    }

    @Test
    func test02() {
        let result = fibonacci(2)
        #expect(result == 1)
    }

    @Test
    func test03() {
        let result = fibonacci(3)
        #expect(result == 2)
    }

    @Test
    func test04() {
        let result = fibonacci(4)
        #expect(result == 3)
    }

    @Test
    func test05() {
        let result = fibonacci(5)
        #expect(result == 5)
    }

    @Test
    func test06() {
        let result = fibonacci(8)
        #expect(result == 21)
    }
}
