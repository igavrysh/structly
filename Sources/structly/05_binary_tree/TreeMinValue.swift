//
//  TreeMinValue.swift
//  MyCLI
//
//  Created by new on 3/25/26.
//

func treeMinValue(_ root: TreeNode<Int>?) -> Int {
    let q = Queue<TreeNode<Int>>()
    if let root {
        q.enqueue(root)
    }
    var res = Int.max
    while !q.isEmpty, let node = q.dequeue() {
        res = min(res, node.val)
        if let left = node.left {
            q.enqueue(left)
        }
        if let right = node.right {
            q.enqueue(right)
        }
    }
    return res
}
