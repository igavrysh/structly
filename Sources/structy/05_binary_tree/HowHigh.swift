//
//  HowHigh.swift
//  MyCLI
//
//  Created by new on 3/29/26.
//

struct Pair<T: Hashable & Sendable> {
    let node: TreeNode<T>
    let height: Int
}

func howHigh(_ root: TreeNode<String>?) -> Int {
    guard let root else { return -1 }
    var stack: [Pair] = [Pair<String>(node: root, height: 0)]
    var maxHeight = 0
    while !stack.isEmpty {
        let p = stack.removeLast()
        maxHeight = max(maxHeight, p.height)
        if let right = p.node.right {
            stack.append(Pair<String>(node: right, height: p.height+1))
        }
        if let left = p.node.left {
            stack.append(Pair<String>(node: left, height: p.height+1))
        }
    }
    return maxHeight
}
