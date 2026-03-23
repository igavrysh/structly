//
//  IsUnivalueList.swift
//  MyCLI
//
//  Created by new on 3/22/26.
//

func isUnivalueList<T: Equatable>(_ head: Node<T>?) -> Bool {
    guard let head else {
        return true
    }

    var node: Node<T>? = head
    while let current = node {
        if current.val != head.val {
            return false
        }
        node = current.next
    }

    return true
}
