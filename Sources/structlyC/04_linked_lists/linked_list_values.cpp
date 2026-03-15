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

std::vector<std::string> linkedListValues(Node *head) {
    Node *node = head;
    std::vector<std::string> vals{};
    while (node != nullptr) {
        vals.push_back(node->val);
        node = node->next;
    }
    return vals;
}

void run() {
    // this function behaves as `main()` for the 'run' command
    // you may sandbox in this function, but should not remove it
}
