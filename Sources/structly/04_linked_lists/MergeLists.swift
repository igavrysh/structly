//
//  MergeLists.swift
//  MyCLI
//
//  Created by new on 3/21/26.
//

func mergeLists2(_ head1: Node<Int>?, _ head2: Node<Int>?) -> Node<Int>? {
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

func mergeLists(_ head1: Node<Int>?, _ head2: Node<Int>?) -> Node<Int>? {
    var tail = Node(0)
    let dummy = tail
    var p1 = head1
    var p2 = head2
    while let p1_ = p1, let p2_ = p2 {
        if p1_.val < p2_.val {
            tail.next = p1_
            p1 = p1_.next
        } else {
            tail.next = p2_
            p2 = p2_.next
        }
        tail = tail.next!
    }

    if p1 == nil {
        tail.next = p2
    } else {
        tail.next = p1
    }

    return dummy.next
}
