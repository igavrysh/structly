//
//  lc0977.swift
//  MyCLI
//
//  Created by new on 3/15/26.
//

class lc0977 {
    func sortedSquares(_ nums: [Int]) -> [Int] {
        var res: [Int] = Array.init(repeating: 0, count: nums.count)
        var l = 0
        var r = nums.count - 1
        var ptr = nums.count - 1
        while l<=r {
            if abs(nums[l]) >= abs(nums[r]) {
                res[ptr] = nums[l] * nums[l]
                l += 1
            } else {
                res[ptr] = nums[r] * nums[r]
                r -= 1
            }
            ptr -= 1
        }
        return res
    }
}
