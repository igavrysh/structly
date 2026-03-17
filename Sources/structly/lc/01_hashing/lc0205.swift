//
//  lc0205.swift
//  MyCLI
//
//  Created by new on 3/16/26.
//

class lc0205 {
    func isIsomorphic(_ s: String, _ t: String) -> Bool {
        let a_s = Array(s)
        let a_t = Array(t)
        if a_s.count != a_t.count {
            return false
        }
        var mapping: [Character: Character] = [:]
        var refs: Set<Character> = []
        for i in 0..<a_s.count {
            let from = a_s[i]
            let to = a_t[i]
            guard let to = mapping[from] else {
                mapping[from] = to
                if refs.contains(to) {
                    return false
                }
                refs.insert(to)
                continue
            }
            if a_t[i] != to {
                return false
            }
        }
        return true
    }
}
