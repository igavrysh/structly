//
//  lc0643.swift
//  MyCLI
//
//  Created by new on 3/15/26.
//

class lc0643 {
    func findMaxAverage(_ nums: [Int], _ k: Int) -> Double {
        var sum: Double = 0
        var res: Double = 0
        for i in 0...nums.count-1 {
            sum += Double(nums[i])
            if i < k - 1 {
                continue
            }
            if i-k >= 0 {
                sum -= Double(nums[i-k])
            }
            if i==k-1 {
                res = sum / Double(k)
            } else {
                res = max(res, sum / Double(k))
            }
        }
        return res
    }
}

class lc0643_2 {
    func findMaxAverage(_ nums: [Int], _ k: Int) -> Double {
        var sum = nums[0..<k].reduce(0, +)
        var max_sum = sum
        if nums.count > k {
            for i in k..<nums.count {
                sum = sum + nums[i] - nums[i-k]
                max_sum = max(max_sum, sum)
            }
        }
        return Double(max_sum) / Double(k)
    }
}
