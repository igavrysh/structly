//
//  lc557.swift
//  MyCLI
//
//  Created by new on 3/18/26.
//

class lc0557 {
    func reverseWords(_ s: String) -> String {
        return s
            .split(separator: " ")
            .map{ String($0.reversed()) }
            .joined(separator: " ")
    }
}
