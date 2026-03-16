//
//  lc2090.swift
//  MyCLI
//
//  Created by new on 3/15/26.
//

class lc2090 {
    func getAverages(_ nums: [Int], _ k: Int) -> [Int] {
        let n = nums.count
        var res = Array.init(repeating: -1, count: n)
        let window_size = 2*k+1
        if n < window_size {
            return res
        }
        var sum = nums[0..<window_size].reduce(0, +)
        res[k] = Int(Double(sum) / Double(window_size))
        if k+1 <= n-1-k {
            for i in k+1..<n-k {
                sum = sum - nums[i-k-1] + nums[i+k]
                res[i] = Int(Double(sum) / Double(window_size))
            }
        }
        return res
    }
}

