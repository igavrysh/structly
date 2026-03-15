//
//  Palindrome.swift
//  MyCLI
//
//  Created by new on 3/14/26.
//

func palindrome(_ s: String) -> Bool {
    func is_p(l: String.Index, r: String.Index, res: Bool, s: String) -> Bool {
        print("\(l) =?= \(r) res: \(s[l]==s[r])")
        if res == false {
            return false
        }
        if l >= r {
            return true
        }
        return is_p(
            l: s.index(after: l),
            r: s.index(before: r),
            res: s[l] == s[r] && res,
            s: s)
    }
    return s.count == 0
        || is_p(l: s.startIndex, r: s.index(before: s.endIndex), res: true, s: s)
}
