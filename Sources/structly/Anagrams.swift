//
//  longestWord.swift
//  MyCLI
//
//  Created by new on 3/10/26.
//

func anagrams(_ s1: String, _ s2: String) -> Bool {
    var fq: [Character: Int] = [:]
    var counter = 0
    for c in s1 {
        fq[c, default: 0] += 1
        counter += 1
    }
    for c in s2 {
        if fq[c, default: 0] == 0 {
            return false
        }
        fq[c, default: 0] -= 1
        counter -= 1
    }
    return counter == 0
}
