//
//  DepthFirstvalues.swift
//  MyCLI
//
//  Created by new on 3/23/26.
//

func depthFirstValues2(_ root: TreeNode<String>?) -> [String] {
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

func cache_depth(node: TreeNode<String>?, cache: inout [String]) {
    guard let node else {
        return
    }
    cache.append(node.val)
    cache_depth(node: node.left, cache: &cache)
    cache_depth(node: node.right, cache: &cache)
}

func depthFirstValues(_ root: TreeNode<String>?) -> [String] {
    var acc: [String] = []
    cache_depth(node: root, cache: &acc)

    return acc
}
