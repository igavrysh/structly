//
//  linked_list_find.h
//  MyCLI
//
//  Created by new on 3/16/26.
//

#include <string>

class Node {
  public:
    std::string val;
    Node *next;

    Node(std::string initialVal) {
        val = initialVal;
        next = nullptr;
    }
};

bool linkedListFind(Node *head, std::string target) {
    Node *node = head;
    while (node != nullptr) {
        if (node->val == target) {
            return true;
        }
        node = node->next;
    }
    return false;
}

bool linkedListFind1(Node *head, std::string target) {
    if (head == nullptr) {
        return false;
    }
    if (head->val == target) {
        return true;
    }
    return linkedListFind(head->next, target);
}
