#include <vector>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <iostream>

using namespace std;

int dfs(char v, unordered_map<char, int>& depth, unordered_map<char, vector<char>>& G) {
    int max_depth = -1;
    for (char next_v : G[v]) {
        if (depth[next_v] != -1) {
            max_depth = max(max_depth, depth[next_v]);
        } else {
            max_depth = max(max_depth, dfs(next_v, depth, G));
        }
    }
   
    depth[v] = 1 + max_depth;
    
    return depth[v];
}

int longestPath(unordered_map<char, vector<char>> G) {
    unordered_map<char, int> depth{};
    for (tuple<char, vector<char>> tuple : G) {
        depth[get<0>(tuple)] = -1;
    }
    int longest = 0;
    for (tuple<char, vector<char>> tuple : G) {
        char v = get<0>(tuple);
        longest = max(longest, dfs(v, depth, G));
    }

    return longest;
}

void test_00() {
    unordered_map<char, vector<char>> graph {
        { 'a', {'c', 'b'} },
        { 'b', {'c'} },
        { 'c', {} }
    };
    int output = longestPath(graph); // -> 2
    bool passed = output == 2;
    cout << "test_00: " << (passed ? "PASSED" : "FAILED") << "; output: " << output <<endl;
}

void test_01() {
    unordered_map<char, vector<char>> graph {
        { 'a', {'c', 'b'} },
        { 'b', {'c'} },
        { 'c', {} },
        { 'q', {'r'} },
        { 'r', {'s', 'u', 't'} },
        { 's', {'t'} },
        { 't', {'u'} },
        { 'u', {} }
    };
    int output = longestPath(graph); // -> 2
    bool passed = output == 4;
    cout << "test_01: " << (passed ? "PASSED" : "FAILED") << "; output: " << output << endl;
}

void test_02() {
    unordered_map<char, vector<char>> graph {
        { 'h', {'i', 'j', 'k'} },
        { 'g', {'h'} },
        { 'i', {} },
        { 'j', {} },
        { 'k', {} },
        { 'x', {'y'} },
        { 'y', {} }
    };
    int output = longestPath(graph); // -> 2
    bool passed = output == 2;
    cout << "test_02: " << (passed ? "PASSED" : "FAILED") << "; output: " << output << endl;
}

int main(int argc, char const *argv[]) {
    test_00();
    test_01();
    test_02();
    return 0;
}
