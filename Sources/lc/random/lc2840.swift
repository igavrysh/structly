//
//  lc2840.swift
//  MyCLI
//
//  Created by new on 3/30/26.
//

class lc2840 {
    func checkStrings(_ s1: String, _ s2: String) -> Bool {
        var oddFqs: Dictionary<Character, Int> = [:]
        var evenFqs: Dictionary<Character, Int> = [:]
        for (i, c) in s1.enumerated() {
            if i%2==0 {
                evenFqs[c, default: 0] += 1
            } else {
                oddFqs[c, default: 0] += 1
            }
        }

        for (i, c) in s2.enumerated() {
            if i%2 == 0 {
                if evenFqs[c, default: 0] == 0 {
                    return false
                }
                evenFqs[c, default: 0] -= 1
            } else {
                if oddFqs[c, default: 0] == 0 {
                    return false
                }
                oddFqs[c, default: 0] -= 1
            }
        }

        return true
    }
}
