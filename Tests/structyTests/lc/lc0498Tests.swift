//
//  lc0498Tests.swift
//  MyCLI
//
//  Created by new on 3/21/26.
//

import Testing
@testable import structy

@Suite
final class lc0498Tests {

    @Test
    func lc0498_test1() {
        let mat = [[1,2,3],[4,5,6],[7,8,9]]
        #expect(lc0498.findDiagonalOrder(mat) == [1,2,4,7,5,3,6,8,9])
    }

    @Test
    func lc0498_test2() {
        let mat = [[1,2],[3,4]]
        #expect(lc0498.findDiagonalOrder(mat) == [1,2,3,4])
    }
}
