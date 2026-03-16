//
//  1832.swift
//  MyCLI
//
//  Created by new on 3/16/26.
//

class lc1832 {
    func checkIfPangram(_ sentence: String) -> Bool {
        var counter = 0
        var set: Set<Character> = []
        for ch in sentence {
            if set.contains(ch) {
                continue
            }
            set.insert(ch)
            counter += 1
            if counter == 26 {
                return true
            }
        }
        return false
    }
}
