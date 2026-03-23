//
//  LinkedListValues.swift
//  MyCLI
//
//  Created by new on 3/15/26.
//

func linkedListValues2<T>(_ head: Node<T>?) -> [T] {
    var vals = [T]()
    var node = head
    while node != nil {
        vals.append(node!.val)
        node = node?.next
    }

    return vals
}

func linkedListValues<T>(_ head: Node<T>?) -> [T] {
    func rec(node: Node<T>?, acc: inout [T]) {
        guard let node else {
            return
        }
        acc.append(node.val)
        rec(node: node.next, acc: &acc)
    }
    var acc: [T] = []
    rec(node: head, acc: &acc)
    
    return acc
}
