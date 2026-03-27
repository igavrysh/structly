//
//  lc1436.swift
//  MyCLI
//
//  Created by new on 3/27/26.
//

class lc1436 {
    func destCity(_ paths: [[String]]) -> String {
        var outgoing: [String: Int] = [:]
        var dest_cities: Set<String> = []
        for path in paths {
            let src = path[0]
            let dst = path[1]
            outgoing[src, default: 0] += 1
            if outgoing[dst, default: 0] == 0 {
                dest_cities.insert(dst)
            }
            if dest_cities.contains(src) {
                dest_cities.remove(src)
            }
        }
        return dest_cities.first! ?? ""
    }
}
