//
//  lc2225.swift
//  MyCLI
//
//  Created by new on 3/16/26.
//

class lc2225 {
    func findWinners(_ matches: [[Int]]) -> [[Int]] {
        var numberOfPlayers = 0
        for match in matches {
            let winner = match.first!
            let looser = match.last!
            numberOfPlayers = max(numberOfPlayers, max(winner, looser))
        }

        var players: [Int] = Array(repeating: -1, count: numberOfPlayers + 1)
        for match in matches {
            let winner = match.first!
            let looser = match.last!

            if players[winner] == -1 {
                players[winner] = 0
            }

            if players[looser] == -1 {
                players[looser] = 1
            } else {
                players[looser] += 1
            }
        }

        var result: [[Int]] = [[], []]

        for player in 1...numberOfPlayers where players[player] != -1 {
            if players[player] == 0 {
                result[0].append(player)
            } else if players[player] == 1 {
                result[1].append(player)
            }
        }

        return result
    }
}
