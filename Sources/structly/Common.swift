//
//  Common.swift
//  MyCLI
//
//  Created by new on 3/15/26.
//

import Foundation

final class Node<T: Sendable>: @unchecked Sendable {
    private let lock = NSLock()
    private var _val: T
    private var _next: Node<T>?

    var next: Node<T>?

    var val: T {
        get { lock.withLock { _val } }
        set { lock.withLock { _val = newValue } }
    }

    init(_ value: T) {
        self._val = value
        self._next = nil
    }
}

final class TreeNode<T: Sendable>: @unchecked Sendable {
    private let lock = NSLock()
    private var _val: T
    private var _left: TreeNode<T>?
    private var _right: TreeNode<T>?

    var left: TreeNode<T>?
    var right: TreeNode<T>?

    var val: T {
        get { lock.withLock { _val } }
        set { lock.withLock { _val = newValue } }
    }

    init(_ value: T) {
        self._val = value
        self._left = nil
        self._right = nil
    }
}
/*
 | head | -> ... -> | node k | -> ... -> | tail | -> null
 */
final class Queue<T: Sendable>: @unchecked Sendable {
    private var head: Node<T>?
    private var tail: Node<T>?
    private let queueLock = NSLock()
    private var size: Int = 0


    var isEmpty: Bool {
        queueLock.withLock {
            head == nil
        }
    }

    func enqueue(_ value: T) {
        let newNode = Node(value)
        queueLock.withLock {
            guard let tailNode = tail else {
                self.tail = newNode
                self.head = newNode
                return
            }

            tailNode.next = newNode
            tail = newNode
            size += 1
        }
    }

    func dequeue() -> T? {
        queueLock.withLock {
            guard let headNode = head else {
                return nil
            }

            let value = headNode.val
            head = headNode.next

            if head == nil {
                tail = nil
            }

            size -= 1

            return value
        }
    }

    func peek() -> T? {
        queueLock.withLock {
            return head?.val
        }
    }
}
