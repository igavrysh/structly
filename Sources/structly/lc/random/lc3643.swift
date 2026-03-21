//
//  lc3643.swift
//  MyCLI
//
//  Created by new on 3/21/26.
//

class lc3643 {
    func reverseSubmatrix(_ grid: [[Int]], _ x: Int, _ y: Int, _ k: Int) -> [[Int]] {
        let rows = grid.count
        let cols = grid[0].count
        var res = Array.init(repeating: Array.init(repeating: 0, count: cols), count: rows)
        for i in 0..<rows {
            for j in 0..<cols {
                if i >= x && i < x+k && j >= y && j < y+k {
                    res[x+(k-1-(x-i))][j] = grid[i][j]
                } else {
                    res[i][j] = grid[i][j]
                }
            }
        }
        return res
    }
}
