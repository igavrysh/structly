//
//  SumOfLengthsTests.swift
//  MyCLI
//
//  Created by new on 3/14/26.
//

import Testing
@testable import structy
@Suite
final class SumOfLengthsTests {
    @Test
    func test00() {
        let result = sum_of_lengths(["goat", "cat", "purple"])
        #expect(result == 13)
    }

    @Test
    func test01() {
        let result = sum_of_lengths(["bike", "at", "pencils", "phone"])
        #expect(result == 18)
    }

    @Test
    func test02() {
        let result = sum_of_lengths([])
        #expect(result == 0)
    }

    @Test
    func test03() {
        let result = sum_of_lengths(["", " ", "  ", "   ", "    ", "     "])
        #expect(result == 15)
    }

    @Test
    func test04() {
        let result = sum_of_lengths(["0", "313", "1234567890"])
        #expect(result == 14)
    }
}
