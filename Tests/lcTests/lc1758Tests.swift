//
//  lc1758Tests.cpp
//  MyCLI
//
//  Created by new on 3/7/26.
//

import Testing
@testable import lc

@Suite
final class lc1758Tests {

    @Test
    func lc1758_test1() {
        let s = "0100"
        #expect(lc1758.minOperations(s) == 1)
    }

    @Test
    func lc1758_test2() {
        let s = "10"
        #expect(lc1758.minOperations(s) == 0)
    }

    @Test
    func lc1758_test3() {
        let s = "1111"
        #expect(lc1758.minOperations(s) == 2)
    }
}
