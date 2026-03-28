//
//  TreePathFinder.swift
//  MyCLI
//
//  Created by new on 3/27/26.
//

func pathFinder<T: Hashable>(_ root: TreeNode<T>?, _ target: T) -> [T] {
    var acc: [T] = []
    guard let root else {
        return acc
    }

    var q = Queue<TreeNode<T>>()
    var ch2p: [T: TreeNode<T>]
    q.enqueue(root)

    while !q.isEmpty {
        guard let node = q.dequeue() else {
            continue
        }

        if node.val == target {
            return []
        }
    }

    return acc.reversed()
}

func pathFinder1<T: Equatable>(_ root: TreeNode<T>?, _ target: T) -> [T] {
    func path_finder(_ node: TreeNode<T>?, _ acc: inout [T]) -> Bool {
        guard let node else {
            return false
        }

        if node.val == target {
            acc.append(node.val)
            return true
        }

        let l = path_finder(node.left, &acc)
        if l == true {
            acc.append(node.val)
            return true
        }

        let r = path_finder(node.right, &acc)
        if r == true {
            acc.append(node.val)
            return true
        }

        return false
    }

    var acc: [T] = []
    _ = path_finder(root, &acc)

    return acc.reversed()
}
