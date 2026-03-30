//
//  BottomRightValue.swift
//  MyCLI
//
//  Created by new on 3/29/26.
//

//       3
//    /    \
//   11     10
//  / \      \
// 4   -2     1

func bottomRightValue<T>(_ root: TreeNode<T>?) -> T? {
    guard let root else {
        return nil
    }

    let q: Queue<TreeNode<T>> = Queue<TreeNode<T>>()
    q.enqueue(root)
    var current: T? = nil
    while !q.isEmpty {
        guard let node = q.dequeue() else {
            return nil
        }
        current = node.val
        if let left = node.left {
            q.enqueue(left)
        }
        if let right = node.right {
            q.enqueue(right)
        }
    }

    return current
}
