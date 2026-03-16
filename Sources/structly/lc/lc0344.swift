//
//  lc0344.swift
//  MyCLI
//
//  Created by new on 3/15/26.
//

class lc0344 {
    func reverseString(_ s: inout [Character]) {
        let n = s.count
        for i in 0..<n/2 {
            let tmp = s[i]
            s[i] = s[n-1-i]
            s[n-1-i] = tmp
        }
    }

    func reverseString2(_ s: inout [Character]) {
        s.reverse()
    }
}
