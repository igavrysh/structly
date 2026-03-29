//
//  ExclusiveItems.swift
//  MyCLI
//
//  Created by new on 3/12/26.
//

func exclusiveItems(_ a: [Int], _ b: [Int]) -> [Int] {
    var res = Set(a)
    for x in b {
        if res.contains(x) {
            res.remove(x)
        } else {
            res.insert(x)
        }
    }

    return [Int](res)
}

func exclusiveItems1(_ a: [Int], _ b: [Int]) -> [Int] {
    let inter = Set(a).intersection(Set(b))
    var res = [Int]()
    for x in a {
        if !inter.contains(x) {
            res.append(x)
        }
    }

    for x in b {
        if !inter.contains(x) {
            res.append(x)
        }
    }

    return res
}
