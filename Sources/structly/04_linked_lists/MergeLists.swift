//
//  MergeLists.swift
//  MyCLI
//
//  Created by new on 3/21/26.
//

func mergeLists(_ head1: Node<Int>?, _ head2: Node<Int>?) -> Node<Int>? {
    guard let head1 else {
        return head2
    }

    guard let head2 else {
        return head1
    }

    if head1.val < head2.val {
        head1.next = mergeLists(head2, head1.next)
        return head1
    } else {
        head2.next = mergeLists(head1, head2.next)
        return head2
    }
}

func mergeLists2(_ head1: Node<Int>?, _ head2: Node<Int>?) -> Node<Int>? {
//
//    var node1 = head1
//    var node2 = head2
//    var tail = Node(0)
//    var head = tail
//    
//    if node1 != nil && node1?.val < node2?.val {
//        tail.next = node1
//    } else {
//        tail.next = node2
//    }
//
//    while node1 != nil && node2 != nil {
//        if node1!.val < node2!.val {
//            node1?.next = node2
//
//
//        }
//    }
    return nil
}
