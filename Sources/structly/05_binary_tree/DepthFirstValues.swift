//
//  DepthFirstvalues.swift
//  MyCLI
//
//  Created by new on 3/23/26.
//

func depthFirstValues(_ root: TreeNode<String>?) -> [String] {
    var res: [String] = []

    guard let root else {
        return res
    }

    var stack: [TreeNode<String>] = [root]
    while !stack.isEmpty, let node = stack.popLast() {
        res.append(node.val)
        if let right = node.right {
            stack.append(right)
        }
        if let left = node.left {
            stack.append(left)
        }
    }

    return res
}

func depthFirstValues1(_ root: TreeNode<String>?) -> [String] {
    guard let root else {
        return []
    }

    var left = depthFirstValues(root.left)
    left.insert(root.val, at: 0)
    let right = depthFirstValues(root.right)
    return left + right
}
