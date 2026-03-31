//
//  lc2946.swift
//  MyCLI
//
//  Created by new on 3/27/26.
//

class lc2946 {
    func areSimilar(_ mat: [[Int]], _ k: Int) -> Bool {
        let rows = mat.count
        let cols = mat[0].count
        let k_short = k % cols
        for i in 0..<rows {
            if i%2 == 0 {
                for j in 0..<cols {
                    if mat[i][j] != mat[i][(j+cols-k_short)%cols] {
                        return false
                    }
                }
            } else {
                for j in 0..<cols {
                    if mat[i][j] != mat[i][(j+k_short)%cols] {
                        return false
                    }
                }
            }
        }
        return true
    }
}
