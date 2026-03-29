//
//  Intersection.swift
//  MyCLI
//
//  Created by new on 3/12/26.
//

func intersection(_ a: [Int], _ b: [Int]) -> [Int] {
    var m = [Int: Int]()
    for x in a {
        m[x, default: 0] += 1
    }
    var res = [Int]()
    for x in b {
        if let fq = m[x] {
            res.append(x)
            m[x] = fq - 1
            if m[x] == 0 {
                m.removeValue(forKey: x)
            }
        }
    }
    
    return res.sorted()
}
