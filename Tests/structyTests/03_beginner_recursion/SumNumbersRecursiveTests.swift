//
//  SumNumbersRecursiveTests.swift
//  MyCLI
//
//  Created by new on 3/14/26.
//

import Testing
@testable import structy
@Suite
final class SumNumbersRecursiveTests {
    @Test
    func test00() {
        let result = sumNumbersRecursive([5, 2, 9, 10])
        #expect(result == 26)
    }

    @Test
    func test01() {
        let result = sumNumbersRecursive([1, -1, 1, -1, 1, -1, 1])
        #expect(result == 1)
    }

    @Test
    func test02() {
        let result = sumNumbersRecursive([])
        #expect(result == 0)
    }

    @Test
    func test03() {
        let result = sumNumbersRecursive([1000, 0, 0, 0, 0, 0, 1])
        #expect(result == 1001)
    }

    @Test
    func test04() {
        let result = sumNumbersRecursive([700, 70, 7])
        #expect(result == 777)
    }

    @Test
    func test05() {
        let result = sumNumbersRecursive([-10, -9, -8, -7, -6, -5, -4, -3, -2, -1])
        #expect(result == -55)
    }

    @Test

    func test06() {
        let result = sumNumbersRecursive([0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0])
        #expect(result == 0)
    }

    @Test

    func test07() {
        let result = sumNumbersRecursive([123456789, 12345678, 1234567, 123456, 12345, 1234, 123, 12, 1, 0])
        #expect(result == 137174205)
    }
}
