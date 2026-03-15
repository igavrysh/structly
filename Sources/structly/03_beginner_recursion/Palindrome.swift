//
//  Palindrome.swift
//  MyCLI
//
//  Created by new on 3/14/26.
//

func palindrome(_ s: String) -> Bool {
    func is_p(l: String.Index, r: String.Index) -> Bool {
        if l >= r {
            return true
        }
        if s[l] != s[r] {
            return false
        }
        return is_p(l: s.index(after: l), r: s.index(before: r))
    }
    return s.isEmpty
        || is_p(l: s.startIndex, r: s.index(before: s.endIndex))
}
