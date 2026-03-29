//
//  MaxRootToLeafPathSum.swift
//  MyCLI
//
//  Created by new on 3/25/26.
//

func maxPathSum(_ node: TreeNode<Int>?) -> Int {
    guard let node else {
        return Int.min
    }

    if node.left == nil && node.right == nil {
        return node.val
    }

    return node.val + max(maxPathSum(node.left), maxPathSum(node.right)
    );
}
