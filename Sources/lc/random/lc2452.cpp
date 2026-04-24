//
// Created by new on 4/22/26.
//

#include <vector>
#include <iostream>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isLeaf;

    TrieNode() : children{}, isLeaf(false) {}
};

class lc2452 {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        TrieNode* root = new TrieNode();
        for (string& word : dictionary) {
            add_word(word, root);
        }
        vector<string> res;
        for (string& query : queries) {
            if (dfs(0, 0, root, query)) {
                res.push_back(query);
            }
        }

        return res;
    }

    bool dfs(int i, int skips_used, TrieNode* node, string query) {
        if (skips_used > 2) {
            return false;
        }

        if (i == query.size()) {
            return node->isLeaf;
        }

        char ch = query[i];
        bool res = false;
        if (node->children[ch - 'a'] != nullptr) {
            res = dfs(i+1, skips_used, node->children[ch - 'a'], query);
            if (res) {
                return res;
            }
        }
        for (int j = 0; j < 26; j++) {
            if (node->children[j] == nullptr) {
                continue;
            }
            res = dfs(i+1, skips_used+1, node->children[j], query);
            if (res) {
                return res;
            }
        }

        return false;
    }

    void add_word(const string& word, TrieNode* root) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isLeaf = true;
    }
};

void test_00() {
    vector<string> queries = {"word","note","ants","wood"};
    vector<string> dictionary = {"wood","joke","moat"};
    lc2452 sol = lc2452();
    vector<string> res = sol.twoEditWords(queries, dictionary);
    vector<string> expected{"word","note","wood"};
    bool passed = res == expected;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
}
