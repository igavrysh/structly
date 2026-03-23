//
//  reverse_linked_list.h
//  MyCLI
//
//  Created by new on 3/18/26.
//

#include <string>

class Node {
public:
    std::string val;
    Node* next;

    Node(std::string initialVal) {
        val = initialVal;
        next = nullptr;
    }
};

Node* rev_helper(Node* node, Node* prev) {
    if (node == nullptr) {
        return prev;
    }

    Node* newHead = rev_helper(node->next, node);
    node->next = prev;

    return newHead;
}

Node* reverseList(Node* head) {
    return rev_helper(head, nullptr);
}

Node* reverseList1(Node* head) {
    Node* node = head;
    Node* node_prev = nullptr;
    while (node != nullptr) {
        Node* tmp = node->next;
        node->next = node_prev;
        node_prev = node;
        node = tmp;
    }

    return node_prev;
}
