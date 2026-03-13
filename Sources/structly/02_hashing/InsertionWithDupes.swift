//
//  InsertionWithDupes.swift
//  MyCLI
//
//  Created by new on 3/13/26.
//

func intersectionWithDupes(_ a: [String], _ b: [String]) -> [String] {
    var map = [String: Int]()
    for str in a {
        map[str, default: 0] += 1
    }
    var res = [String]()
    for str in b {
        if map[str, default: 0] > 0 {
            res.append(str)
            map[str, default: 0] -= 1
        }
    }
    return res
}
