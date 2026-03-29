//
//  LinkedListFind.swift
//  MyCLI
//
//  Created by new on 3/16/26.
//

func linkedListFind <T: Equatable>(_ node: Node<T>?, _ target: T) -> Bool {
    guard let node else {
        return false
    }
    return node.val == target || linkedListFind(node.next, target)
}

func linkedListFind1 <T: Equatable>(_ head: Node<T>?, _ target: T) -> Bool {
    var current = head
    while let node = current {
        if node.val == target {
            return true
        }
        current = node.next
    }
    return false
}
