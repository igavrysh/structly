//
//  TreePathFinder.swift
//  MyCLI
//
//  Created by new on 3/27/26.
//

/// DFS - push into stack:
/// * in case both left and right children are available for current node, push  nil, node.right, node.left into the stack
/// * in case only left child is available: nil, node.left
/// * in case only right child ...
/// * in case leaf node, e.g. no left or right nodes for current node: just push nil into the stack
/// pop from the stack - and if the value is nil, means last path element should also be poped, e.g. we completed
/// traversal of all current node children and have not found anything, meaning current path is exhausted and we need to return
/// to previous level to check all options there too
fileprivate enum Step<T> {
    case enter(TreeNode<T>)
    case leave
}

func pathFinder<T: Equatable>(_ root: TreeNode<T>?, _ target: T) -> [T] {
    guard let root else { return [] }

    var stack: [Step<T>] = [.enter(root)]
    var path: [T] = []

    while let step = stack.popLast() {
        switch step {
        case .enter(let node):
            path.append(node.val)
            if node.val == target {
                return path
            }

            stack.append(.leave)
            if let right = node.right {
                stack.append(.enter(right))
            }

            if let left = node.left {
                stack.append(.enter(left))
            }

        case .leave:
            path.removeLast()
        }
    }

    return path
}

/// BFS implementation with child to parent Dictionary mapping under the hood to reconstruct the path
/// * Why Equitable? - cos there is equality test below e.g. node.val == target
///also can store a path to parent, and root eventually, duplicating last list node on branching left and right
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
func pathFinderBFS<T: Equatable>(_ root: TreeNode<T>?, _ target: T) -> [T] {
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

/// Recursive - StackOverflow for large enough Tree
/// To demo, change name of function to pathFinder
func pathFinderRecursive<T: Equatable>(_ root: TreeNode<T>?, _ target: T) -> [T] {
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

