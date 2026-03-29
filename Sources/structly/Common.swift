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

final class TreeNodeSimple<T> {
    var val: T
    var left: TreeNodeSimple<T>?
    var right: TreeNodeSimple<T>?

    init(_ value: T) {
        self.val = value
        self.left = nil
        self.right = nil
    }
}

final class Managed<T>: @unchecked Sendable {
    private var value: T
    private let lock = NSRecursiveLock()

    init(_ value: T) { self.value = value }

    func read() -> T { lock.withLock { value } }
    func write(_ newValue: T) { lock.withLock { value = newValue } }
}

final class TreeNode<T: Hashable & Sendable>: Hashable, Sendable  {
    let id = UUID()
    private let _val: Managed<T>
    private let _left: Managed<TreeNode?>
    private let _right: Managed<TreeNode?>

    init(_ val: T) {
        self._val = Managed(val)
        self._left = Managed(nil)
        self._right = Managed(nil)
    }

    var val: T {
        get { _val.read() }
        set { _val.write(newValue) }
    }

    var left: TreeNode? {
        get { _left.read() }
        set { _left.write(newValue) }
    }

    var right: TreeNode? {
        get { _right.read() }
        set { _right.write(newValue) }
    }

    func hash(into hasher: inout Hasher) { hasher.combine(id) }
    static func == (lhs: TreeNode, rhs: TreeNode) -> Bool { lhs.id == rhs.id }

    deinit {
        // We use a local array as a manual stack to avoid
        // the CPU call stack limit.
        var stack: [TreeNode<T>] = []

        // Safely move children to our stack and nil them out
        // to break the recursive chain.
        if let l = _left.read() {
            stack.append(l)
            _left.write(nil)
        }
        if let r = _right.read() {
            stack.append(r)
            _right.write(nil)
        }

        while !stack.isEmpty {
            let node = stack.removeLast()

            // Push children of the current node onto our manual stack
            if let l = node._left.read() {
                stack.append(l)
                node._left.write(nil)
            }
            if let r = node._right.read() {
                stack.append(r)
                node._right.write(nil)
            }
            // As the 'node' variable goes out of scope here,
            // it is deallocated. Since its children are already nil,
            // the deallocation is now shallow (non-recursive).
        }
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
