//
//  longestWord.swift
//  MyCLI
//
//  Created by new on 3/6/26.
//

/**
 longest word
 Write a function, longestWord, that takes in a sentence string as an argument. The function should return the longest word in the sentence. If there is a tie, return the word that occurs later in the sentence.

 You can assume that the sentence is non-empty.

 longestWord("what a wonderful world"); // -> "wonderful"
 longestWord("have a nice day"); // -> "nice"
 longestWord("the quick brown fox jumped over the lazy dog"); // -> "jumped"
 longestWord("who did eat the ham"); // -> "ham"
 */

class S01_BigO_LongestWord {
    func longestWord(_ s: String) -> String {
        var res = ""
        for word in s.split(separator: " ") {
            if word.count >= res.count {
                res = String(word)
            }
        }
        return res
    }
}

