//
//  SumNumbersRecursive.swift
//  MyCLI
//
//  Created by new on 3/14/26.
//

func sumNumbersRecursive(_ numbers: [Int]) -> Int {
    func sum(i: Int, total: Int) -> Int {
        if i == numbers.count {
            return total
        }
        return sum(i: i+1, total: total + numbers[i])
    }
    return sum(i: 0, total: 0)
}

func sumNumbersRecursive1(_ numbers: [Int]) -> Int {
    func sum(_ numbers: ArraySlice<Int>) -> Int {
        if numbers.isEmpty {
            return 0
        }
        return numbers[numbers.startIndex] + sum(numbers.dropFirst())
    }
    return sum(numbers[...])
}
