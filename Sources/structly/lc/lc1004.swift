//
//  lc1004.swift
//  MyCLI
//
//  Created by new on 3/15/26.
//

class lc1004 {
    func longestOnes(_ nums: [Int], _ k: Int) -> Int {
        var zeros = 0
        var ones = 0
        var l = 0
        var max_len = 0
        for r in 0..<nums.count {
            if nums[r] == 1 { ones+=1 } else { zeros += 1 }
            while zeros > k && l <= r {
                if nums[l] == 1 { ones -= 1 } else { zeros -= 1 }
                l += 1
            }
            max_len = max(max_len, r-l+1)
        }
        return max_len
    }
}
