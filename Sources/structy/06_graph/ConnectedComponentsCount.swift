//
//  ConnectedComponentsCount.swift
//  MyCLI
//
//  Created by new on 3/30/26.
//

func connectedComponentsCount(_ graph: [Int: [Int]]) -> Int {
    func dfs(_ v: Int, _ G: [Int: [Int]], _ visited: inout Set<Int>) {
        guard let neighbors = G[v] else {
            return
        }

        for next_v in neighbors {
            if visited.contains(next_v) {
                continue
            }

            visited.insert(next_v)
            dfs(next_v, G, &visited)
        }
    }

    var visited: Set<Int> = []
    var counter = 0
    for v in graph.keys {
        if visited.contains(v) {
            continue
        }

        dfs(v, graph, &visited)
        counter += 1
    }

    return counter
}
