//
//  lc0525.swift
//  MyCLI
//
//  Created by new on 3/15/26.
//

class lc0525 {
    func findMaxLength(_ nums: [Int]) -> Int {
        var m = [0: -1]
        var balance = 0
        var res = 0
        for (i, num) in nums.enumerated() {
            if num == 0 {
                balance -= 1
            } else {
                balance += 1
            }
            if let firstIdx = m[balance] {
                res = max(res, i-firstIdx)
            } else {
                m[balance] = i
            }
        }
        return res
    }
}
