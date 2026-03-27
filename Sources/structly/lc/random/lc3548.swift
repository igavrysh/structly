//
//  lc3548.swift
//  MyCLI
//
//  Created by new on 3/26/26.
//

class lc3548 {
    private func can_partition(_ grid: [[Int]]) -> Bool {
        let rows = grid.count
        let cols = grid[0].count
        if cols < 2 {
            return false
        }
        var total_sum = 0
        var total_col_sum: [Int] = Array(repeating: 0, count: cols)

        for j in 0..<cols {
            for i in 0..<rows {
                total_sum += grid[i][j]
                total_col_sum[j] += grid[i][j]
            }
        }

        var fking_r_vals: [Int:Int] = [:]
        var r_vals: [Int:Int] = [:]
        var total_r_sum = 0
        var total_l_sum = total_col_sum[0]
        for j in 1..<cols {
            for i in 0..<rows {
                r_vals[grid[i][j], default: 0] += 1
            }
            total_r_sum += total_col_sum[j]
        }
        fking_r_vals[grid[0][cols-1], default: 0] += 1
        fking_r_vals[grid[rows-1][cols-1], default: 0] += 1

        var l_vals: [Int:Int] = [:]
        for i in 0..<rows {
            l_vals[grid[i][0], default: 0] += 1
        }
        var fking_l_vals: [Int:Int] = [:]
        fking_l_vals[grid[0][0], default: 0] += 1
        fking_l_vals[grid[rows-1][0], default: 0] += 1

        if total_r_sum == total_l_sum
            || fking_l_vals.keys.contains(total_l_sum - total_r_sum)
            || r_vals.keys.contains(total_r_sum - total_l_sum)
        {
            return true
        }

        for j in 1..<cols-1 {
            total_l_sum += total_col_sum[j]
            total_r_sum -= total_col_sum[j]
            for i in 1..<rows {
                let k = grid[i][j]
                l_vals[k, default: 0] += 1
                r_vals[k, default: 0] -= 1
                if r_vals[k, default: 0] == 0 {
                    r_vals.removeValue(forKey: k)
                }
            }

            if total_r_sum == total_l_sum
                || l_vals.keys.contains(total_l_sum - total_r_sum)
                || (r_vals.keys.contains(total_r_sum - total_l_sum) && j < cols-1)
            {
                return true
            }
        }

        if fking_r_vals.keys.contains(total_r_sum - total_l_sum) {
            return true
        }

        return false
    }

    func canPartitionGrid(_ grid: [[Int]]) -> Bool {
        if can_partition(grid) {
            return true
        }
        let rows = grid.count
        let cols = grid[0].count
        var grid_t = Array(repeating: Array(repeating: 0, count: rows), count: cols)
        for i in 0..<rows {
            for j in 0..<cols {
                grid_t[j][i] = grid[i][j]
            }
        }
        if can_partition(grid_t) {
            return true
        }
        return false
    }
}
