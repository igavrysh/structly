//
//  lc2225.swift
//  MyCLI
//
//  Created by new on 3/16/26.
//

class lc2225 {
    func findWinners(_ matches: [[Int]]) -> [[Int]] {
        var losses: [Int: Int] = [:]
        for match in matches {
            losses[match[1], default: 0] += 1
        }
        var zeroLosses: [Int] = []
        var oneLoss: [Int] = []
        for (loser_id, loses) in losses {
            if loses == 0 {
                zeroLosses.append(loser_id)
            } else if loses == 1 {
                oneLoss.append(loser_id)
            }
        }
        zeroLosses.sort()
        oneLoss.sort()
        return [zeroLosses, oneLoss]
    }
}
