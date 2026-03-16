//
//  lc1878.swift
//  MyCLI
//
//  Created by new on 3/16/26.
//

class lc1878 {
    func getBiggestThree(_ grid: [[Int]]) -> [Int] {
        func rhombusSum(i cI: Int, j cJ: Int, r: Int) -> Int {
            var res = 0
            var gridI = -1
            var gridJ = -1
            for j in -r...r {
                if j < 0 {
                    res = res + grid[cI-(r+j)][cJ+j]
                    if j != -r {
                        res = res + grid[cI+(r+j)][cJ+j]
                    }
                } else {
                    res = res + grid[cI-(r-j)][cJ+j]
                    if j != r {
                        res = res + grid[cI+(r-j)][cJ+j]
                    }
                }
            }
            return res
        }
        var arr = [Int]()
        for i in 0..<grid.count {
            for j in 0..<grid[0].count {
                let max_r = min(i, j, grid.count-1-i, grid[0].count-1-j)
                for r in 0...max_r {
                    let res = rhombusSum(i: i, j: j, r: r)
                    if arr.firstIndex(of: res) == nil {
                        arr.append(res)
                        arr.sort(by: >)
                        if arr.count > 3 {
                            arr.removeLast()
                        }
                    }
                }
            }
        }
        return arr
    }
}
