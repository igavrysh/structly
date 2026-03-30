//
//  AllTreePaths.swift
//  MyCLI
//
//  Created by new on 3/29/26.
//

func allTreePaths(_ root: TreeNode<String>?) -> [[String]] {

    func all_tree_paths(_ node: TreeNode<String>?) -> [[String]] {
        guard let node else {
            return [[]]
        }

        if node.left == nil && node.right == nil {
            return [[node.val]]
        }

        var res: [[String]] = []

        if let left = node.left {
            for var path in all_tree_paths(left) {
                path.append(node.val)
                res.append(path)
            }
        }

        if let right = node.right {
            for var path in all_tree_paths(right) {
                path.append(node.val)
                res.append(path)
            }
        }

        return res
    }

    var res = all_tree_paths(root)
    for i in res.indices {
        res[i].reverse()
    }

    return res
}
