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
