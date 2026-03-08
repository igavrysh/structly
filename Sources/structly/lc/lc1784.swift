/**
1784. Check if Binary String Has at Most One Segment of Ones
Easy
Topics
premium lock icon
Companies

Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.

Example 1:

Input: s = "1001"
Output: false
Explanation: The ones do not form a contiguous segment.

Example 2:

Input: s = "110"
Output: true
 

Constraints:

1 <= s.length <= 100
s[i]​​​​ is either '0' or '1'.
s[0] is '1'.
*/

//import Testing

class lc1784 {
    static func checkOnesSegment_firstIteration(_ s: String) -> Bool {
        let chrs: [Character] = Array(s)
        var firstChunkSeen = false
        for (i, ch) in chrs.enumerated() {
            if ch == "0" && i-1>=0 && chrs[i-1] == "1" {
                firstChunkSeen = true
            } else if ch == "1" && firstChunkSeen {
                return false
            }
        }
        return true
    }

    static func checkOnesSegment(_ s: String) -> Bool {
        return !s.contains("01")
    }
//
//    @Test 
//    func lc1784_test1() async throws {
//        let s = "1001"
//        #expect(checkOnesSegment(s) == false)
//    }
//
//    @Test 
//    func lc1784_test2() async throws {
//        let s = "110"
//        #expect(checkOnesSegment(s) == true)
//    }
//
//    @Test 
//    func lc1784_test3() async throws {
//        let s = "1011"
//        #expect(checkOnesSegment(s) == false)
//    }
}
