//
//  GetNodeValue.swift
//  MyCLI
//
//  Created by new on 3/18/26.
//

func getNodeValue(_ head: Node<String>?, _ index: Int) -> String {
    guard let head else { return "" }
    if index == 0 {
        return head.val
    }

    return getNodeValue(head.next, index-1)
}

func getNodeValue1(_ head: Node<String>?, _ index: Int) -> String {
    var node = head
    var counter = 0
    while let currentNode = node, counter < index {
        node = currentNode.next
        counter += 1
    }

    return node?.val ?? ""
}
