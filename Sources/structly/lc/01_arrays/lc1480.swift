//
//  lc1480.swift
//  MyCLI
//
//  Created by new on 3/15/26.
//

class lc1480 {
    func runningSum(_ nums: [Int]) -> [Int] {
        var res: [Int] = Array.init(repeating: 0, count: nums.count)
        for i in 0..<nums.count {
            res[i] = nums[i] + (i-1>=0 ? res[i-1] : 0)
        }
        return res
    }
}
