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
    Node* dummyHead = new Node(-1);
    Node* tail = dummyHead;
    Node* current = head;
    while (current != nullptr) {
        if (tail->val == current->val) {
        } else {
            tail->next = new Node(current->val);
            tail = tail->next;
        }
        current = current->next;
    }
    return dummyHead->next;
}

Node* undupeSortedLinkedList_v1(Node* head) {
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