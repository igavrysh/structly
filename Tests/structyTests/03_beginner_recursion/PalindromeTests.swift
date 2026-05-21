//
//  PalindromeTests.swift
//  MyCLI
//
//  Created by new on 3/14/26.
//

import Testing
@testable import structy
@Suite
final class PalindromeTests {
    @Test
    func test00() {
        let result = palindrome("pop")
        #expect(result == true)
    }

    @Test
    func test01() {
        let result = palindrome("kayak")
        #expect(result == true)
    }

    @Test
    func test02() {
        let result = palindrome("pops")
        #expect(result == false)
    }

    @Test
    func test03() {
        let result = palindrome("boot")
        #expect(result == false)
    }

    @Test
    func test04() {
        let result = palindrome("rotator")
        #expect(result == true)
    }

    @Test
    func test05() {
        let result = palindrome("abcbca")
        #expect(result == false)
    }

    @Test
    func test06() {
        let result = palindrome("")
        #expect(result == true)
    }

    @Test
    func test_ololo() {
        let result = palindrome("👨‍👩‍👧‍👦􀫊👨‍👩‍👧‍👦")
        #expect(result == true)
    }

    @Test
    func test_ololo2() {
        let result = palindrome("􀥺􀪯􁎖")
        #expect(result == false)
    }

    @Test
    func test_ololo3() {
        let result = palindrome("􀥺􀪯􀥺")
        #expect(result == true)
    }
}
