//
//  lc0654.swift
//  structy
//
//  Created by new on 5/16/26.
//

class Solution {
    public class TreeNode {
        public var val: Int
        public var left: TreeNode?
        public var right: TreeNode?
        public init() { self.val = 0; self.left = nil; self.right = nil; }
        public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
        public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
            self.val = val
            self.left = left
            self.right = right
        }
    }

    func constructMaximumBinaryTree(_ nums: [Int]) -> TreeNode? {
        if nums.isEmpty {
            return nil
        }
        if nums.count == 1 {
            return TreeNode(nums[0])
        }

        let maxIndex = nums.indices.max(by: { nums[$0] < nums[$1] })!
        var node = TreeNode(nums[maxIndex])
        let leftSlice = nums[..<maxIndex]
        node.left = constructMaximumBinaryTree(Array(leftSlice))
        let rightSlice = nums[(maxIndex+1)...]
        node.right = constructMaximumBinaryTree(Array(rightSlice))

        return node
    }

}
