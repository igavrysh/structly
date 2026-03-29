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

import Testing

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

    @Test
    func s01_big_O_test1() async throws {
        #expect(longestWord("what a wonderful world") == "wonderful")
    }

    @Test
    func s01_big_O_test2() async throws {
        #expect(longestWord("have a nice day") == "nice")
    }

    @Test
    func s01_big_O_test3() async throws {
        #expect(longestWord("the quick brown fox jumped over the lazy dog") == "jumped")
    }

    @Test
    func s01_big_O_test4() async throws {
        #expect(longestWord("who did eat the ham") == "ham")
    }
}


