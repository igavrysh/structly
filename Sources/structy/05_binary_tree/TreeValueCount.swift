//
//  TreeValueCount.swift
//  MyCLI
//
//  Created by new on 3/29/26.
//


func treeValueCount(_ root: TreeNode<Int>?, _ target: Int) -> Int {
    func targetfq_r(_ node: TreeNode<Int>?, _ t: Int) -> Int {
        guard let node else {
            return 0
        }

        return (node.val == target ? 1 : 0) + targetfq_r(node.left, t) + targetfq_r(node.right, t)
    }

    func targetfq_i(_ root: TreeNode<Int>?, _ t: Int) -> Int {
        let q = Queue<TreeNode<Int>>()
        if let root {
            q.enqueue(root)
        }

        var res = 0
        while !q.isEmpty {
            guard let node = q.dequeue() else {
                continue
            }

            if node.val == t {
                res += 1
            }

            if let l = node.left {
                q.enqueue(l)
            }
            if let r = node.right {
                q.enqueue(r)
            }
        }

        return res
    }

    return targetfq_i(root, target)
}
