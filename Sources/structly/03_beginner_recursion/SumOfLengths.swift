//
//  SumOfLengths.swift
//  MyCLI
//
//  Created by new on 3/14/26.
//

func sum_of_lengths(_ strings: [String]) -> Int {
    func sol(i: Int, acc: Int, strings: [String]) -> Int {
        if i == strings.count {
            return acc
        }
        return sol(i: i+1, acc: acc+strings[i].count, strings: strings)
    }
    return sol(i: 0, acc: 0, strings: strings)
}
