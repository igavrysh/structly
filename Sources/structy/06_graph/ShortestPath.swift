//
//  ShortestPath.swift
//  MyCLI
//
//  Created by new on 3/31/26.
//

func shortestPath(_ edges: [[String]], _ nodeA: String, _ nodeB: String) -> Int {
    var G: Dictionary<String, Set<String>> = [:]
    for edge in edges {
        let from = edge[0]
        let to = edge[1]
        G[from, default: Set<String>()].insert(to)
        G[to, default: Set<String>()].insert(from)
    }

    let q = Queue<(String, Int)>()
    var visited = Set<String>()
    q.enqueue((nodeA, 0))
    visited.insert(nodeA)
    while !q.isEmpty {
        guard let (v, d) = q.dequeue() else {
            continue
        }

        if v == nodeB {
            return d
        }


        for next_v in G[v, default: Set<String>()] {
            if visited.contains(next_v) {
                continue
            }

            q.enqueue((next_v, d + 1))
        }
    }

    return -1
}


