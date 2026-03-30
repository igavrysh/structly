//
//  lc3477.swift
//  MyCLI
//
//  Created by new on 3/20/26.
//

class lc3477 {
    class BiNode<T> {
        var val: T
        var l: BiNode<T>?
        var r: BiNode<T>?

        convenience init(_ val: T) {
            self.init(val, l: nil, r: nil)
        }

        init(_ val: T, l: BiNode<T>?, r: BiNode<T>?) {
            self.val = val
            self.l = l
            self.r = r
        }
    }

    func tree(_ l: Int, _ r: Int, _ vals: [Int]) -> BiNode<Int>? {
        if l == r {
            return BiNode(vals[l])
        }
        let m = l + (r - l) / 2
        let l = tree(l, m, vals)
        let r = tree(m+1, r, vals)
        return BiNode(max(l?.val ?? 0, r?.val ?? 0), l: l, r: r)
    }

    func insert(_ fruit: Int, at node: BiNode<Int>?, cntr: inout Int) {
        guard let node else {
            return
        }
        if node.l == nil && node.r == nil {
            node.val = 0
            return
        }
        if let l_node = node.l, l_node.val >= fruit {
            insert(fruit, at: l_node, cntr: &cntr)
            node.val = max(node.l?.val ?? 0, node.r?.val ?? 0)
        } else if let r_node = node.r, r_node.val >= fruit {
            insert(fruit, at: r_node, cntr: &cntr)
            node.val = max(node.l?.val ?? 0, node.r?.val ?? 0)
        } else {
            cntr += 1
        }
    }

    func numOfUnplacedFruits(_ frts: [Int], _ bskts: [Int]) -> Int {
        let root = tree(0, bskts.count - 1, bskts)
        var cntr = 0
        for fruit in frts {
            if let rootval = root?.val, rootval < fruit {
                cntr += 1
                continue
            }
            insert(fruit, at: root, cntr: &cntr)
        }
        return cntr
    }
}
