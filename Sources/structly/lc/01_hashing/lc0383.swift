//
//  lc0383.swift
//  MyCLI
//
//  Created by new on 3/19/26.
//

class lc0383 {
    func canConstruct(_ ransomNote: String, _ magazine: String) -> Bool {
        func fq(_ text: String) -> [Character: Int] {
            return Array(ransomNote).reduce(into: [Character: Int]()) { fq_dict, chr in
                fq_dict[chr, default: 0] += 1
            }
        }
        var ransomMap = fq(ransomNote)
        var counter = 0
        var idx = magazine.startIndex
        let target_len = ransomNote.count
        while idx < magazine.endIndex {
            let ch = magazine[idx]
            if ransomMap[ch, default: 0] > 0 {
                ransomMap[ch, default: 0] -= 1
                counter += 1
                if counter == target_len {
                    return true
                }
            } else {
                return false
            }
            idx = magazine.index(after: idx)
        }
        return counter == target_len
    }
}
