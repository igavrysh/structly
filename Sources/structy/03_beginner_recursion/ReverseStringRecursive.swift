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

func reverseStringOlolo(_ s: inout String) -> String {
    var l = s.startIndex
    var r = s.index(before: s.endIndex)

    while l < r {
        let charL = s[l]
        let charR = s[r]

        s.replaceSubrange(l...l, with: String(charR))
        s.replaceSubrange(r...r, with: String(charL))

        s.formIndex(after: &l)
        s.formIndex(before: &r)
    }

    return s
}


