//
//  lc2906.swift
//  MyCLI
//
//  Created by new on 3/23/26.
//

class Solution {
    func constructProductMatrix(_ grid: [[Int]]) -> [[Int]] {
        let MOD = 12345
        let rows = grid.count
        let cols = grid[0].count
        var suffix = Array(
            repeating: Array(repeating: 0, count: cols),
            count: rows)
        var acc = 1
        for i in stride(from: rows-1, through: 0, by: -1) {
            for j in stride(from: cols-1, through: 0, by: -1) {
                suffix[i][j] = acc
                acc = (acc * grid[i][j]) % MOD
            }
        }
        acc = 1
        var res = Array(
            repeating: Array(repeating: 0, count: cols),
            count: rows)
        for i in 0..<rows {
            for j in 0..<cols {
                res[i][j] = (acc * suffix[i][j]) % MOD
                acc = (acc * grid[i][j]) % MOD
            }
        }
        return res
    }
}
