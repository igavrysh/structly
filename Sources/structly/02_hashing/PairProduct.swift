//
//  PairProduct.swift
//  MyCLI
//
//  Created by new on 3/12/26.
//

func pairProduct(_ numbers: [Int], _ target: Int) -> (Int, Int) {
    var m = [Int : Int]()
    for (i, num) in numbers.enumerated() {
        if num == 0 || target % num != 0 {
            continue
        }
        let complement = target / num;
        if let found = m[complement] {
            return (found, i)
        }
        m[num] = i
    }
    return (-1, -1)
}
