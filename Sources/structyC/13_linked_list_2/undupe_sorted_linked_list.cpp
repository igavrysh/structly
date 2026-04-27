//
// Created by new on 4/27/26.
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

Node* undupeSortedLinkedList(Node* head) {
    Node* node = head;
    while (node != nullptr) {
        if (node->next != nullptr) {
            if (node->val == node->next->val) {
                node->next = node->next->next;
            } else {
                node = node -> next;
            }
        } else {
            node = node->next;
        }
    }
    return head;
}