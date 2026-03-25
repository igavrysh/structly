//
//  RemoveNode.swift
//  MyCLI
//
//  Created by new on 3/22/26.
//

func removeNode(_ head: Node<String>?, _ target: String) -> Node<String>? {
    let dummy = Node("foobar")
    dummy.next = head
    var node: Node<String>? = head
    var prevNode = dummy
    while let currentNode = node {
        if currentNode.val == target {
            prevNode.next = currentNode.next
            break
        }
        prevNode = currentNode
        node = currentNode.next
    }

    return dummy.next
}
