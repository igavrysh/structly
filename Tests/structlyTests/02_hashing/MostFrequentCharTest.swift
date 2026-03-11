//
//  MostFrequentChar.swift
//  MyCLI
//
//  Created by new on 3/10/26.
//

import Testing
@testable import structly

@Suite
final class MostFrequentCharTests {
    @Test("tests")
    func test00() async throws {
        #expect(mostFrequentChar("bookeeper") == "e")
        #expect(mostFrequentChar("david") == "d")
        #expect(mostFrequentChar("mississippi") == "i")
        #expect(mostFrequentChar("potato") == "o");
        #expect(mostFrequentChar("eleventennine") == "e")
        #expect(mostFrequentChar("riverbed") == "r")
    }
}
