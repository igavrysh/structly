//
//  merge_lists.cpp
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

Node* mergeLists(Node* head1, Node* head2) {
    Node* dummy = new Node(-1);
    Node* tail = dummy;
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->val <= head2->val) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    tail->next = head1 != nullptr ? head1 : head2;

    return dummy->next;
}

Node* mergeLists2(Node* head1, Node* head2) {
    if (head1 == nullptr) {
        return head2;
    }

    if (head2 != nullptr && head1->val > head2->val) {
        Node* tmp = head1;
        head1 = head2;
        head2 = tmp;
    }

    head1->next = mergeLists(head1->next, head2);

    return head1;
}

