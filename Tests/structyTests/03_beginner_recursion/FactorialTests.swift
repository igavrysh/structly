//
//  Factorial.swift
//  MyCLI
//
//  Created by new on 3/14/26.
//

import Testing
@testable import structy
@Suite
final class FactorialTests {
    @Test
    func test00() {        let result = factorial(3)
        #expect(result == 6)
    }

    @Test
    func test01() {        let result = factorial(6)
        #expect(result == 720)
    }

    @Test
    func test02() {        let result = factorial(18)
        #expect(result == 6402373705728000)
    }

    @Test
    func test03() {        let result = factorial(1)
        #expect(result == 1)
    }

    @Test
    func test04() {        let result = factorial(13)
        #expect(result == 6227020800)
    }

    @Test
    func test05() {        let result = factorial(0)
        #expect(result == 1)
    }
}
