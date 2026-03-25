//
//  TreeSum.swift
//  MyCLI
//
//  Created by new on 3/24/26.
//


func treeSum(_ node: TreeNode<Int>?) -> Int {
    let q = Queue<TreeNode<Int>>()
    if let node {
        q.enqueue(node)
    }

    var res = 0
    while q.peek() != nil, let cnode = q.dequeue() {
        res += cnode.val
        if let left = cnode.left {
            q.enqueue(left )
        }
        if let right = cnode.right {
            q.enqueue(right)
        }
    }
    
    return res
}

func treeSum1(_ node: TreeNode<Int>?) -> Int {
    guard let node else {
        return 0
    }

    return node.val
        + (node.left.map(treeSum1(_:)) ?? 0)
        + (node.right.map(treeSum1(_:)) ?? 0)
}
