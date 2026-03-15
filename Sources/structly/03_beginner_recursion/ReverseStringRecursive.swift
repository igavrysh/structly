//
//  ReverseStringRecursive.swift
//  MyCLI
//
//  Created by new on 3/14/26.
//

func reverseString(_ s: String) -> String {
    func rev(sub: Substring) -> String {
        if sub.count <= 1 {
            return String(sub)
        }
        let firstPart = sub.dropFirst()
        let secondPart = String(sub.first!)
        return rev(sub: firstPart) + secondPart
    }
    return rev(sub: s[...])
}
