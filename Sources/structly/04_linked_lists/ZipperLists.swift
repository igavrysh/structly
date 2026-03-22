//
//  ZipperLists.swift
//  MyCLI
//]\\\\\\\\\\\

//  Created by new on 3/19/26.
//


func zipperLists5<T>(_ head1: Node<T>?, _ head2: Node<T>?) -> Node<T>? {
    guard let head1 else {
        return head2
    }
    head1.next = zipperLists5(head2, head1.next)
    return head1
}

protocol Defaultable {
    static var defaultValue: Self { get }
}

func zipperLists6<T>(_ head1: Node<T>?, _ head2: Node<T>?) -> Node<T>? where T: Defaultable {
    var tail = Node<T>(T.defaultValue)
    tail.next = head1 ?? head2

    let senti = tail
    
    var (p1, p2) = (head1, head2)
    while let current = p1 {
        tail.next = current
        tail = tail.next!
        p1 = current.next
        (p1, p2) = (p2, p1)
    }

    tail.next = p2

    return senti.next
}

extension Int: Defaultable {
    static var defaultValue: Int { 0 }
}

extension String: Defaultable {
    static var defaultValue: String { "" }
}

func zipperLists4<T>(_ head1: Node<T>?, _ head2: Node<T>?) -> Node<T>? {
    if head1 == nil {
        return head2
    }
    var node1: Node<T>? = head1
    var node2: Node<T>? = head2

    var counter = 0
    var tail: Node<T> = node1!
    node1 = node1?.next
    while node1 != nil && node2 != nil {
        tail.next = counter % 2 == 0 ? node2 : node1
        if counter % 2 == 0 {
            tail.next = node2
            tail = node2!
            node2 = node2!.next
        } else {
            tail.next = node1
            tail = node1!
            node1 = node1!.next
        }
        counter += 1
    }

    tail.next = node1 ?? node2

    return head1
}

func zipperLists2<T>(_ head1: Node<T>?, _ head2: Node<T>?) -> Node<T>? {
    guard let head1 else {
        return head2
    }
    guard let head2 else {
        return head1
    }

    let head1Next = head1.next
    head1.next = head2
    head2.next = zipperLists2(head1Next, head2.next)

    return head1
}

func zipperLists1<T>(_ head1: Node<T>?, _ head2: Node<T>?) -> Node<T>? {
    func zip(_ node1: Node<T>?, _ node2: Node<T>?, _ tail: Node<T>, _ counter: Int) {
        guard let node1 else {
            tail.next = node2
            return
        }

        guard let node2 else {
            tail.next = node1
            return
        }

        if counter % 2 == 0 {
            tail.next = node1
            zip(node1.next, node2, node1, counter + 1)
        } else {
            tail.next = node2
            zip(node1, node2.next, node2, counter + 1)
        }
    }

    guard let head1 else {
        return head2;
    }

    zip(head1.next, head2, head1, 1)

    return head1
}
