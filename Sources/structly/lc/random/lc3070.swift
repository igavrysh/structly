//
//  lc3070.swift
//  MyCLI
//
//  Created by new on 3/17/26.
//

class lc3070 {
    func countSubmatrices(_ grid: [[Int]], _ k: Int) -> Int {
        let rows = grid.count
        let cols = grid[0].count
        var res = 0
        var dp = Array.init(repeating: 0, count: cols)
        var dp_prev = Array.init(repeating: 0, count: cols)
        for i in 0..<rows {
            for j in 0..<cols {
                dp[j] = grid[i][j]
                    + (i > 0 ? dp_prev[j] : 0)
                    + (j > 0 ? dp[j-1] : 0)
                    - (i>0 && j>0 ? dp_prev[j-1] : 0)
                if dp[j] <= k {
                    res += 1
                } else {
                    return res
                }
                var tmp = dp_prev
                dp_prev = dp
                dp = tmp
            }
        }
        return res
    }
}
