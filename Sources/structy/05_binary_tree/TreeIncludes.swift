//
//  TreeIncludes.swift
//  MyCLI
//
//  Created by new on 3/24/26.
//

func treeIncludes(_ node: TreeNode<String>?, _ target: String) -> Bool {
    guard let node else {
        return false
    }

    return node.val == target || treeIncludes(node.left, target) || treeIncludes(node.right, target)
}
