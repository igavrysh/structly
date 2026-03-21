//
//  lc3477Tests.swift
//  MyCLI
//
//  Created by new on 3/20/26.
//

import Testing
@testable import structly

@Suite
final class lc3477Tests {

    @Test
    func lc3477_test1() {
        let fruits = [4,2,5]
        let baskets = [3,5,4]
        let sol = lc3477()
        let res = sol.numOfUnplacedFruits(fruits, baskets)
        #expect(res == 1)
    }
}
