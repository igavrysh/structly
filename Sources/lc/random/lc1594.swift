//
//  lc1594.swift
//  MyCLI
//
//  Created by new on 3/23/26.
//

class lc1594 {
    func maxProductPath(_ grid: [[Int]]) -> Int {
        let MOD = 1_000_000_007
        let rows = grid.count, cols = grid[0].count
        var dp_min = Array.init(repeating: Int.max, count: cols)
        var dp_max = Array.init(repeating: Int.min, count: cols)
        var dp_min_prev = Array.init(repeating: Int.max, count: cols)
        var dp_max_prev = Array.init(repeating: Int.min, count: cols)
        for i in 0..<rows {
            for j in 0..<cols {
                let grid_cell = grid[i][j]
                if i == 0 && j == 0 {
                    dp_min[j] = grid_cell
                    dp_max[j] = grid_cell
                    continue
                }
                let options = [
                    i-1>=0 ? (grid_cell * dp_min_prev[j]) : nil,
                    j-1>=0 ? (grid_cell * dp_min[j-1]) : nil,
                    i-1>=0 ? (grid_cell * dp_max_prev[j]) : nil,
                    j-1>=0 ? (grid_cell * dp_max[j-1]) : nil,
                ]
                dp_min[j] = (options.reduce(Int.max, { acc, num in
                    if let num {
                        return min(acc, num)
                    }
                    return acc
                }))
                dp_max[j] = (options.reduce(Int.min, { acc, num in
                    if let num {
                        return max(acc, num)
                    }
                    return acc
                }))
            }
            (dp_min_prev, dp_max_prev) = (dp_min, dp_max)
        }
        return dp_max[cols-1] >= 0 ? dp_max[cols-1]%MOD : -1
    }
}
