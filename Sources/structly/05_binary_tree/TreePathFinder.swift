//
//  TreePathFinder.swift
//  MyCLI
//
//  Created by new on 3/27/26.
//

/// also can store a path to parent, and root eventually
/*

final class PathNode<T> {
    let val: T
    let prev: PathNode<T>?
    init(_ val: T, prev: PathNode<T>? = nil) {
        self.val = val
        self.prev = prev
    }
}
// Queue stores: (Current Tree Node, Path to reach it)
var q: [(node: TreeNode<T>, path: PathNode<T>)] = [(root, PathNode(root.val))]

*/

func pathFinder<T>(_ root: TreeNode<T>?, _ target: T) -> [T] {
    var acc: [T] = []
    guard let root else {
        return acc
    }

    let q = Queue<TreeNode<T>>()
    var child2parent: [TreeNode<T>: TreeNode<T>] = [:]
    var found: TreeNode<T>? = nil

    q.enqueue(root)
    while !q.isEmpty {
        guard let node = q.dequeue() else {
            continue
        }

        if node.val == target {
            found = node
            break
        }

        if let leftNode = node.left {
            child2parent[leftNode] = node
            q.enqueue(leftNode)
        }

        if let rightNode = node.right {
            child2parent[rightNode] = node
            q.enqueue(rightNode)
        }
    }
    var node = found
    while let node_ = node {
        acc.append(node_.val)
        node = child2parent[node_]
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
