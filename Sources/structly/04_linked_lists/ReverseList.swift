//
//  ReverseList.swift
//  MyCLI
//
//  Created by new on 3/18/26.
//

func reverseList(_ head: Node<String>?) -> Node<String>? {
    func rev(node: Node<String>?, prevNode: Node<String>?) -> Node<String>? {
        guard let node else {
            return prevNode
        }
        let next = node.next
        node.next = prevNode

        return rev(node: next, prevNode: node)
    }

    return rev(node: head, prevNode: nil)
}

func reverseList1(_ head: Node<String>?) -> Node<String>? {
    var prevNode: Node<String>? = nil
    var node: Node<String>? = head
    while let currentNode = node {
        let nextNode = currentNode.next
        currentNode.next = prevNode
        prevNode = currentNode
        node = nextNode
    }
    
    return prevNode
}
