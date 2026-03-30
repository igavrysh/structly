//
//  depth_first_print.cpp
//  MyCLI
//
//  Created by new on 3/29/26.
//

#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <queue>

void depthFirstPrint(std::unordered_map<std::string, std::vector<std::string>> graph, std::string start) {
    std::stack<std::string> stack;
    stack.push(start);
    while (!stack.empty()) {
        std::string current = stack.top();
        std::cout<<current<<std::endl;
        stack.pop();
        for (std::string neighbor : graph[current]) {
            stack.push(neighbor);
        }
    }
}

void bredthFirstPrint(std::unordered_map<std::string, std::vector<std::string>> graph, std::string start) {
    std::queue<std::string> queue;
    queue.push(start);
    while (queue.size() > 0) {
        std::string current = queue.front();
        std::cout<<current<<std::endl;
        queue.pop();
        for (std::string neighbor : graph[current]) {
            queue.push(neighbor);
        }
    }
}

void depthFirstPrint_r(std::unordered_map<std::string, std::vector<std::string>> graph, std::string current) {
    std::cout<<current<<std::endl;
    for (std::string neighbor : graph[current]) {
        depthFirstPrint_r(graph, neighbor);
    }
}

void run_depth_first_print() {
    std::unordered_map<std::string, std::vector<std::string>> graph {
        { "a", { "b", "c" } },
        { "b", { "d" } },
        { "c", { "e" } },
        { "d", { "f" } },
        { "e", { } },
        { "f", { } }
    };
    depthFirstPrint(graph, "a");
}
