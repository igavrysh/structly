//
//  MostFrequentChar.swift
//  MyCLI
//
//  Created by new on 3/10/26.
//

func mostFrequentChar(_ s: String) -> Character {
    var fq = [Character: Int]()
    var first_idx = [Character: Int]()
    var max_fq = -1
    var max_fq_idx = -1

    var max_fq_ch = s.first ?? " "
    for (i, ch) in s.enumerated() {
        fq[ch, default: 0] += 1
        if fq[ch, default: 0] == 1 {
            first_idx[ch] = i
        }

        if (max_fq < fq[ch, default: 0]) || (max_fq == fq[ch, default: 0] && first_idx[ch, default: 0] < first_idx[max_fq_ch, default: 0])  {
            max_fq = fq[ch, default: 0]
            max_fq_ch = ch
            max_fq_idx = first_idx[ch, default: 0]
        }
    }

    return max_fq_ch
}
