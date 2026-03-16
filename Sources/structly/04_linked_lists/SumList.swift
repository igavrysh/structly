//
//  SumList.swift
//  MyCLI
//
//  Created by new on 3/16/26.
//

func sumList(_ head: Node<Int>?) -> Int {
    guard let node = head else { return 0 }
    return node.val + sumList(node.next)
}

func sumList1(_ head: Node<Int>?) -> Int {
    var current = head
    var res = 0
    while let node = current {
        res += node.val
        current = node.next
    }
    return res
}


