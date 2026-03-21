//
//  lc498.swift
//  MyCLI
//
//  Created by new on 3/21/26.
//

class lc0498 {
    static func findDiagonalOrder(_ mat: [[Int]]) -> [Int] {
        let rows = mat.count
        if mat.count == 0 {
            return []
        }
        let cols = mat[0].count
        func diag(_ s_i: Int, _ s_j: Int, _ up: Bool, _ res: inout [Int]) -> (Int, Int) {
            var (i, j) = (s_i, s_j)
            let (d_i, d_j) = up ? (-1, 1) : (1, -1)
            while i >= 0 && i < rows && j >= 0 && j < cols {
                res.append(mat[i][j])
                i += d_i
                j += d_j
            }
            return (i-d_i, j-d_j)
        }
        var (i, j) = (0, 0)
        var res: [Int] = []
        var up = true
        while i < rows && j < cols {
            let (end_i, end_j) = diag(i, j, up, &res)
            up = !up
            if end_j == cols-1 {
                i = end_i+1
                j = cols - 1
                continue
            }
            if end_i == rows-1 {
                i = rows-1
                j = end_j + 1
                continue
            }
            if end_i == 0 {
                i = 0
                j = end_j + 1
                continue
            }
            if (end_j == 0) {
                i = end_i + 1
                j = 0
                continue
            }
        }
        return res
    }
}

