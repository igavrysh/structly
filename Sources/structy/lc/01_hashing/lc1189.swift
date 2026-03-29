//
//  lc1189.swift
//  MyCLI
//
//  Created by new on 3/19/26.
//

class lc1189 {
    func maxNumberOfBalloons(_ text: String) -> Int {
        func fqs(_ text: String) -> [Character: Int] {
            return Array(text).reduce(into: [Character: Int]()) { fq, ch in
                fq[ch, default: 0] += 1
            }
        }

        let fqsText = fqs(text)
        let fqsTarget = fqs("balloon")
        var counter = -1
        for (k, v) in fqsTarget {
            let curr_times = fqsText[k, default: 0] / v
            if counter == -1 {
                counter = curr_times
            }
            counter = min(counter, curr_times)
        }

        return counter
    }
}
