//
//  PairSum.swift
//  MyCLI
//
//  Created by new on 3/12/26.
//

func pairSum(_ numbers: [Int], _ target: Int) -> (Int, Int) {
    var m = [Int: Int]()
    for (i, number) in numbers.enumerated() {
        let find = target - number
        if let found = m[find] {
            return (found, i)
        }
        m[number] = i
    }
    return (-1, -1)
}
