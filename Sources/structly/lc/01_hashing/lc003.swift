//
//  003.swift
//  MyCLI
//
//  Created by new on 3/19/26.
//

class lc003 {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        var set: Set<Character> = []
        var l_index = s.startIndex;
        var res = 0
        for (r, ch) in s.enumerated() {
            while set.contains(ch) {
                set.remove(s[l_index])
                s.formIndex(after: &l_index)
            }
            set.insert(ch)
            res = max(res, r-s.distance(from: s.startIndex, to: l_index)+1)
        }

        return res
    }
}

class lc003_2 {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        var longest = 0
        var indexMap = [Character: Int]()
        var startIndex = 0
        for (i, char) in s.enumerated() {
          if let prevIndex = indexMap[char], prevIndex >= startIndex {
            startIndex = prevIndex + 1
          }

          indexMap[char] = i
          longest = max(longest, i - startIndex + 1)
        }
        return longest
    }
}
