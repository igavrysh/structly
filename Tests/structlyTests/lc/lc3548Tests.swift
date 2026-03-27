//
//  lc3548Tests.swift
//  MyCLI
//
//  Created by new on 3/26/26.
//

import Testing
@testable import structly

@Suite("lc3548Tests")
final class lc3548Tests {
    @Test
    func lc3548_test1() {
        let grid = [[1,2],[3,4]]
        let sol = lc3548()
        let res = sol.canPartitionGrid(grid)
        #expect(res == true)
    }

    @Test
    func lc3548_test3() {
        let grid = [
            [1,2,4],
            [2,3,5]
        ]
        let sol = lc3548()
        let res = sol.canPartitionGrid(grid)
        #expect(res == false)
    }

    @Test
    func lc3548_test926() {
        let grid = [[5,5,6,2,2,2]]
        let sol = lc3548()
        let res = sol.canPartitionGrid(grid)
        #expect(res == true)
    }

    @Test
    func lc3548_test4() async throws {
        let grid = [[73816],[71688]]
        let sol = lc3548()
        let res = sol.canPartitionGrid(grid)
        #expect(res == false)
    }

    @Test
    func lc3548_test_random() async throws {
        let grid = [[1],[1]]
        let sol = lc3548()
        let res = sol.canPartitionGrid(grid)
        #expect(res == true)
    }

    @Test
    func lc3548_test_random2() async throws {
        let grid = [[1,1]]
        let sol = lc3548()
        let res = sol.canPartitionGrid(grid)
        #expect(res == true)
    }

    @Test
    func lc3548_test935() async throws {
        let grid = [[25372],[100000],[100000]]
        let sol = lc3548()
        let res = sol.canPartitionGrid(grid)
        #expect(res == true)
    }

    @Test
    func lc3548_test939() async throws {
        let grid = [[10,5,4,5]]
        let sol = lc3548()
        let res = sol.canPartitionGrid(grid)
        #expect(res == false)
    }

    @Test
    func lc358_test939_1() async throws {
        let grid = [[10,5,4,5]]
        let sol = lc3548()
        let res = sol.canPartitionGrid(grid)
        #expect(res == false)
    }

    @Test
    func lc358_test938() async throws {
        let grid = [[100000],[86218],[100000]]
        let sol = lc3548()
        let res = sol.canPartitionGrid(grid)
        #expect(res == true)
    }

    @Test
    func lc358_test939() async throws {
        let grid = [[100000,90234,100000,100000,100000]]
        let sol = lc3548()
        let res = sol.canPartitionGrid(grid)
        #expect(res == false)
    }

    @Test
    func lc358_test941() async throws {
        let grid = [[1,2,4],[1,6,6],[5,6,7]]
        let sol = lc3548()
        let res = sol.canPartitionGrid(grid)
        #expect(res == true)
    }

    @Test
    func lc358_test941_random() async throws {
        let grid = [[1,1],[2,1],[4,3]]
        let sol = lc3548()
        let res = sol.canPartitionGrid(grid)
        #expect(res == false)
    }

}
