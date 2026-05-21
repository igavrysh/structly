//
//  Tests.swift
//  MyCLI
//
//  Created by new on 3/3/26.
//

import Testing
@testable import structy

@Suite
final class PrimeTests {
    @Test
    func testIsPrime() {
        #expect(isPrime(2))
        #expect(isPrime(3))
        #expect(!(isPrime(4)))
        #expect(isPrime(5))
        #expect(!(isPrime(6)))
        #expect(isPrime(7))
        #expect(!(isPrime(8)))
        #expect(!(isPrime(25)))
        #expect(isPrime(31))
        #expect(isPrime(2017))
        #expect(!(isPrime(2048)))
        #expect(!(isPrime(1)))
        #expect(!(isPrime(713)))
    }

    @Test

    func testLargeNumbers() {
        #expect(isPrime(1000000007))
        #expect(isPrime(7919))
    }
}
