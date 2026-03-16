//
//  lc1413.swift
//  MyCLI
//
//  Created by new on 3/15/26.
//

class lc1413 {
    func minStartValue(_ nums: [Int]) -> Int {
        var startValue = 1
        var acc = 0
        for i in 0..<nums.count {
            acc = acc + nums[i]
            if acc < 1 {
                startValue = max(startValue, 1 - acc)
            }
        }
        return startValue
    }
}
