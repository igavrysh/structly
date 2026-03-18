//
//  get_node_value.cpp
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

std::string getNodeValue(Node* head, int idx) {
    if (head == nullptr) {
        return "";
    }
    if (idx == 0) {
        return head->val;
    }

    return getNodeValue(head->next, idx - 1);
}

std::string getNodeValue2(Node* head, int idx) {
    Node* current = head;
    int count = 0;
    while (current != nullptr) {
        if (count == idx) {
            return current->val;
        }
        current = current->next;
        count += 1;
    }
    return "";
}

std::string getNodeValue1(Node* head, int idx) {
    Node* node = head;
    int i = 0;
    while (node != nullptr && idx < i) {
        node = node->next;
        i++;
    }

    return node != nullptr ? node->val : "";
}

