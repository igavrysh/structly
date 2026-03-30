//
//  is_univalue_list.h
//  MyCLI
//
//  Created by new on 3/22/26.
//

class Node {
public:
    int val;
    Node* next;

    Node(int initialVal) {
        val = initialVal;
        next = nullptr;
    }
};

bool is_uni_list(Node* node, Node* head) {
    if (node == nullptr) {
        return true;
    }
    return node->val == head->val && is_uni_list(node->next, head);
}

bool isUnivalueList(Node* head) {
    return is_uni_list(head, head);
}

bool isUnivalueList2(Node* head) {
    Node* node = head;
    while (node != nullptr) {
        if (head->val != node->val) {
            return false;
        }
        node = node->next;
    }
    return true;
}

