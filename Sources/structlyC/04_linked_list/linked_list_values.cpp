//
//  linked_list_values.cpp
//  MyCLI
//
//  Created by new on 3/15/26.
//

#include <string>
#include <vector>

class Node {
public:
    std::string val;
    Node *next;

    Node(std::string initialVal) {
        val = initialVal;
        next = nullptr;
    }
};

std::vector<std::string> linkedListValuesIter(Node *head) {
    Node *node = head;
    std::vector<std::string> vals{};
    while (node != nullptr) {
        vals.push_back(node->val);
        node = node->next;
    }
    return vals;
}

void linked_list_values_r(Node *head, std::vector<std::string> &values) {
    if (head == nullptr) {
        return;
    }
    values.push_back(head->val);
    linked_list_values_r(head->next, values);
}

std::vector<std::string> linkedListValuesRec(Node *head) {
    std::vector<std::string> values{};
    linked_list_values_r(head, values);
    return values;
}
