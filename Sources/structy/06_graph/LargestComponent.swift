//
//  LargestComponent.swift
//  MyCLI
//
//  Created by new on 3/30/26.
//

func largestComponent(_ graph: [Int: [Int]]) -> Int {
    func explore(_ node: Int, _ visited: inout Set<Int>, _ graph: [Int: [Int]]) -> Int {
        if visited.contains(node) {
            return 0
        }

        var res = 1
        visited.insert(node)

        guard let neighbors = graph[node] else {
            return res
        }

        for neightbor in neighbors{
            res += explore(neightbor, &visited, graph)
        }

        return res
    }

    var visited: Set<Int> = []
    var maxSize = 0
    for (node, _) in graph {
        if visited.contains(node) {
            continue
        }

        let size = explore(node, &visited, graph)
        maxSize = max(maxSize, size)
    }

    return maxSize
}
