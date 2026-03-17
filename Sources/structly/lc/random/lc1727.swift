//
//  lc1727.swift
//  MyCLI
//
//  Created by new on 3/17/26.
//

class lc1727 {
    func largestSubmatrix(_ matrix: [[Int]]) -> Int {
        var matrix = matrix
        let rows = matrix.count
        let cols = matrix[0].count
        for j in 0..<cols {
            for i in 0..<rows {
                if (matrix[i][j] != 0) {
                    matrix[i][j] = 1 + (i-1>=0 ? matrix[i-1][j] : 0)
                }
            }
        }
        var res = 0
        for i in 0..<rows {
            matrix[i].sort(by: >)
            for j in 0..<cols {
                res = max(res, matrix[i][j]*(j+1))
            }
        }
        return res
    }
}
