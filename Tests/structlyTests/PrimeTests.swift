//
//  Tests.swift
//  MyCLI
//
//  Created by new on 3/3/26.
//

import XCTest
@testable import structly

final class PrimeTests: XCTestCase {
    func testIsPrime() {
        XCTAssertTrue(isPrime(2))
        XCTAssertTrue(isPrime(3))
        XCTAssertFalse(isPrime(4))
        XCTAssertTrue(isPrime(5))
        XCTAssertFalse(isPrime(6))
        XCTAssertTrue(isPrime(7))
        XCTAssertFalse(isPrime(8))
        XCTAssertFalse(isPrime(25))
        XCTAssertTrue(isPrime(31))
        XCTAssertTrue(isPrime(2017))
        XCTAssertFalse(isPrime(2048))
        XCTAssertFalse(isPrime(1))
        XCTAssertFalse(isPrime(713))
    }

    func testLargeNumbers() {
        XCTAssertTrue(isPrime(1000000007))
        XCTAssertTrue(isPrime(7919))
    }
}
