//
//  printing.swift
//  MyCLI
//
//  Created by new on 3/15/26.
//

#include <iostream>
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

void printList2(Node *head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->val << std::endl;
        current = current->next;
    }
}

void printList(Node* head) {
    if (head == nullptr) {
        return;
    }
    std::cout << head->val << std::endl;
    printList(head->next);
}

void run() {
    Node a("A");
    Node b("B");
    Node c("C");
    Node d("D");
    a.next = &b;
    b.next = &c;
    c.next = &d;

    // A -> B -> C -> 0 -> null
    printList(&a);
}

