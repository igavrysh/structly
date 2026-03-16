//
//  sum_list.cpp
//  MyCLI
//
//  Created by new on 3/16/26.
//

class Node {
  public:
    int val;
    Node *next;

    Node(int initialVal) {
        val = initialVal;
        next = nullptr;
    }
};

int sumList(Node *head) {
    if (head == nullptr) {
        return 0;
    }
    return head->val + sumList(head->next);
}

int sumList1(Node *head) {
    int sum = 0;
    Node *node = head;
    while (node != nullptr) {
        sum += node->val;
        node = node->next;
    }
    return sum;
}
