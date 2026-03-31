//
//  lc0268.swift
//  MyCLI
//
//  Created by new on 3/16/26.
//

class lc0268 {
    func missingNumber(_ nums: [Int]) -> Int {
        var xor = 0
        for num in nums {
            xor ^= num
        }
        for i in 0...nums.count {
            xor ^= i
        }
        return xor
    }

    func missingNumber2(_ nums: [Int]) -> Int {
        let target = (nums.count + 1) * nums.count / 2
        var sum = 0
        for num in nums {
            sum += num
        }
        return target - sum
    }

    func missingNumber1(_ nums: [Int]) -> Int {
        var nums = nums
        var topFilled = false
        for i in 0..<nums.count {
            var num = nums[i]
            nums[i] = -1
            if num == nums.count {
                topFilled = true
            }
            while num != -1 {
                if num == nums.count {
                    topFilled = true
                    break
                }
                let next = nums[num]
                nums[num] = num
                num = next
            }
        }

        if !topFilled {
            return nums.count
        }
        for i in 0..<nums.count {
            if nums[i] == -1 {
                return i
            }
        }
        return -1
    }
}
