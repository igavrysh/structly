//
//  longest_streak.cpp
//  MyCLI
//
//  Created by new on 3/22/26.
//
#include <algorithm>

class Node {
public:
    int val;
    Node* next;

    Node(int initialVal) {
        val = initialVal;
        next = nullptr;
    }
};

int longestStreak(Node* head) {
    int max_streak = 0;
    int prev_value = 42;
    int current_streak = 0;
    Node *node = head;
    while (node != nullptr) {
        if (node == head || node->val != prev_value) {
            current_streak = 1;
        } else {
            current_streak += 1;
        }

        prev_value = node->val;
        max_streak = std::max(max_streak, current_streak);

        node = node->next;
    }
    return max_streak;
}
