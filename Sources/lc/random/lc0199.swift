//
//  lc0199.swift
//  structy
//
//  Created by new on 5/16/26.
//





class lc0199 {

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
    
    func rightSideView(_ root: TreeNode?) -> [Int] {
        var node = root
        guard let node else {
            return []
        }
        var res: [Int] = []
        res.append(node.val)
        let left = rightSideView(node.left)
        let right = rightSideView(node.right)
        for i in 0..<max(left.count, right.count) {
            if right.count < i {
                res.append(right[i])
            } else {
                res.append(left[i])
            }
        }
        return res
    }
}
