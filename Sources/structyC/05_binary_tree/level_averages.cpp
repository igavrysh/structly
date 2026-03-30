//
//  level_averages.cpp
//  MyCLI
//
//  Created by new on 3/29/26.
//

#include <vector>

class Node {
public:
    float val;
    Node* left;
    Node* right;


    Node(float initialVal) {
        val = initialVal;
        left = nullptr;
        right = nullptr;
    }
};

void fillLevels(Node *node, std::vector<std::vector<float>> &levels, int level) {
    if (node == nullptr) {
        return;
    }

    if (levels.size() == level) {
        levels.push_back(std::vector<float>{node->val});
    } else {
        levels[level].push_back(node->val);
    }

    if (node->left != nullptr) {
        fillLevels(node->left, levels, level + 1);
    }

    if (node->right != nullptr) {
        fillLevels(node->right, levels, level + 1);
    }
}

std::vector<float> calc_averages(std::vector<std::vector<float>> &levels) {
    std::vector<float> res;
    for (int i = 0; i < levels.size(); i++) {
        float acc = 0;
        for (int j = 0; j < levels[i].size(); j++) {
            acc += levels[i][j];
        }
        res.push_back(acc / levels[i].size());
    }
    return res;
}

std::vector<float> levelAverages(Node* root) {
    std::vector<std::vector<float>> levels;
    fillLevels(root, levels, 0);
    
    return calc_averages(levels);
}


