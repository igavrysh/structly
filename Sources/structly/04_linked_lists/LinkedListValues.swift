//
//  LinkedListValues.swift
//  MyCLI
//
//  Created by new on 3/15/26.
//

func linkedListValues2(_ head: Node<String>?) -> [String] {
    var vals = [String]()
    var node = head
    while node != nil {
        vals.append(node!.val)
        node = node?.next
    }
    return vals
}

func linkedListValues(_ head: Node<String>?) -> [String] {
    func rec(node: Node<String>?, acc: inout [String]) {
        guard let node else {
            return
        }
        acc.append(node.val)
        rec(node: node.next, acc: &acc)
    }
    var acc: [String] = []
    rec(node: head, acc: &acc)
    return acc
}
