//
//  0771.swift
//  MyCLI
//
//  Created by new on 3/19/26.
//

class lc0711 {
    func numJewelsInStones(_ jewels: String, _ stones: String) -> Int {
        let jewelsSet = Set(jewels)
        var counter = 0
        for st in Array(stones) {
            if jewelsSet.contains(st) {
                counter += 1
            }
        }
        return counter
    }
}
