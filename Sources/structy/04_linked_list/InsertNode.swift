//
//  InsertNode.swift
//  MyCLI
//
//  Created by new on 3/22/26.
//

func insertNode(_ head: Node<String>?, _ value: String, _ index: Int) -> Node<String>? {
    let dummy = Node("foobar")
    dummy.next = head

    var node: Node<String>? = head
    var prev_node: Node<String> = dummy
    var cntr = 0
    while cntr < index {
        guard let current_node = node else {
            return nil
        }
        prev_node = current_node
        node = current_node.next
        cntr += 1
    }
    let newNode = Node(value)
    prev_node.next = newNode
    newNode.next = node

    return dummy.next
}
