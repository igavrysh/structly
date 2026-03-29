//
//  BredthFirstValues.swift
//  MyCLI
//
//  Created by new on 3/23/26.
//


func breadthFirstValues(_ root: TreeNode<String>?) -> [String] {
    let q = Queue<TreeNode<String>>();
    if let root {
        q.enqueue(root)
    }

    var res: [String] = []
    while !q.isEmpty, let node = q.dequeue() {
        res.append(node.val)
        if let lnode = node.left {
            q.enqueue(lnode)
        }
        if let rnode = node.right {
            q.enqueue(rnode)
        }
    }
    
    return res
}
