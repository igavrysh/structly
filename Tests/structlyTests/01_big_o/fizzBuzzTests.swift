//
//  fizzBuzzTests.swift
//  MyCLI
//
//  Created by new on 3/7/26.
//

import Testing
@testable import structly

@Suite
final class fizzBuzzTests {
    @Test
    func test1() async throws {
        let res = fizzBuzz(11)
        #expect(res == ["1","2","fizz","4","buzz","fizz","7","8","fizz","buzz","11"])
    }

    @Test
    func test2() async throws {
        let res = fizzBuzz(2)
        #expect(res == ["1","2"])
    }
}
