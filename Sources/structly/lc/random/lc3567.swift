//
//  lc3567.swift
//  MyCLI
//
//  Created by new on 3/20/26.
//

// BF solution

class lc3567 {
    func minAbsDiff(_ grid: [[Int]], _ k: Int) -> [[Int]] {
        let rows = grid.count
        let cols = grid[0].count
        var res: [[Int]] = Array.init(repeating: Array.init(repeating: 0, count: cols-k+1), count: rows-k+1)
        for i in 0..<rows-k+1 {
            for j in 0..<cols-k+1 {
                var s: Set<Int> = []
                for x in i..<i+k {
                    for y in j..<j+k {
                        s.insert(grid[x][y])
                    }
                }
                var arr = Array(s)
                arr.sort(by: <)
                var minn = 0
                if arr.count > 1 {
                    minn = arr[1] - arr[0]
                    for i in 1..<arr.count {
                        minn = min(minn, arr[i]-arr[i-1])
                    }
                }
                res[i][j] = minn
            }
        }
        return res
    }
}
