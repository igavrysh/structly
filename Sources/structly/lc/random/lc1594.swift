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
        var dp_min = Array.init(
            repeating: Array.init(
                repeating: Int.max, count: cols), count: rows)
        var dp_max = Array.init(
            repeating: Array.init(
                repeating: Int.min, count: cols), count: rows)
        for i in 0..<rows {
            for j in 0..<cols {
                let grid_cell = grid[i][j]
                if i == 0 && j == 0 {
                    dp_min[i][j] = grid_cell
                    dp_max[i][j] = grid_cell
                    continue
                }
                let options = [
                    i-1>=0 ? (grid_cell * dp_min[i-1][j]) : nil,
                    j-1>=0 ? (grid_cell * dp_min[i][j-1]) : nil,
                    i-1>=0 ? (grid_cell * dp_max[i-1][j]) : nil,
                    j-1>=0 ? (grid_cell * dp_max[i][j-1]) : nil,
                ]
                dp_min[i][j] = (options.reduce(Int.max, { acc, num in
                    if let num {
                        return min(acc, num)
                    }
                    return acc
                }))
                dp_max[i][j] = (options.reduce(Int.min, { acc, num in
                    if let num {
                        return max(acc, num)
                    }
                    return acc
                }))
            }
        }
        return dp_max[rows-1][cols-1] >= 0 ? dp_max[rows-1][cols-1]%MOD : -1
    }
}
