//
//  LongestStreak.swift
//  MyCLI
//
//  Created by new on 3/22/26.
//

func longestStreak<T: Equatable>(_ head: Node<T>?) -> Int {
    func longest(_ node: Node<T>?) -> (Int, Int) {
        guard let node else {
            return (0, 0)
        }

        var (look_ahead_length, global_max) = longest(node.next)
        let res = 1 + (node.val == node.next?.val ? look_ahead_length : 0)

        global_max = max(global_max, res)

        return (res, global_max)
    }

    let (_, global_max) = longest(head)

    return global_max;
}
