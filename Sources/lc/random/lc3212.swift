//
//  lc3212.swift
//  MyCLI
//
//  Created by new on 3/19/26.
//

class lc3212 {
    func numberOfSubmatrices(_ grid: [[Character]]) -> Int {
        let rows = grid.count
        let cols = grid[0].count
        var psum = Array(
            repeating: Array(
                repeating: Array(
                    repeating: 0,
                    count: 2),
                count: grid[0].count),
            count: grid.count)
        var res = 0
        for i in 0..<rows {
            for j in 0..<cols {
                if grid[i][j] == "X" {
                    psum[i][j][0] += 1
                } else if grid[i][j] == "Y" {
                    psum[i][j][1] += 1
                }

                for k in 0..<2 {
                    psum[i][j][k] = psum[i][j][k]
                        + (i-1>=0 ? psum[i-1][j][k] : 0)
                        + (j-1>=0 ? psum[i][j-1][k] : 0)
                        - (i-1>=0 && j-1>=0 ? psum[i-1][j-1][k] : 0)
                }
                if psum[i][j][0] == psum[i][j][1] && psum[i][j][0] > 0 {
                    res += 1
                }
            }
        }
        return res
    }
}
