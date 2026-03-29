//
//  lc3546.swift
//  MyCLI
//
//  Created by new on 3/24/26.
//

class lc3546 {
    func canPartitionGrid(_ grid: [[Int]]) -> Bool {
        let rows = grid.count
        let cols = grid[0].count

        var psum = 0
        for i in 0..<rows {
            for j in  0..<cols {
                psum += grid[i][j]
            }
        }

        var csum = 0
        for i in 0..<rows {
            for j in  0..<cols {
                csum += grid[i][j]
            }
            if 2*csum == psum {
                return true
            }
        }

        csum = 0
        for j in 0..<cols {
            for i in 0..<rows {
                csum += grid[i][j]
            }
            if 2*csum == psum {
                return true
            }
        }

        return false
    }
}
