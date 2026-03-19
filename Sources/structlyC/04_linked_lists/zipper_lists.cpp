//
//  zipper_lists.h
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

Node* zipperLists(Node* head1, Node* head2) {
    if (head1 == nullptr) {
        return head2;
    }

    if (head2 == nullptr) {
        return head1;
    }

    Node* head1Next = head1->next;
    head1->next = head2;
    head2->next = zipperLists(head1Next, head2->next);

    return head1;
}

void zip(Node* node1, Node* node2, Node* tail, int counter) {
    if (node1 == nullptr) {
        tail->next = node2;
        return;
    }

    if (node2 == nullptr) {
        tail->next = node1;
        return;
    }

    if (counter % 2 == 0) {
        tail->next = node1;
        zip(node1->next, node2, tail->next, counter+1);
    } else {
        tail->next = node2;
        zip(node1, node2->next, tail->next, counter+1);
    }
}

Node* zipperLists5(Node* head1, Node* head2) {
    if (head1 == nullptr) {
        return head2;
    }
    zip(head1->next, head2, head1, 1);
    return head1;
}

Node* zipperLists4(Node* head1, Node* head2) {
    Node* tail = head1;
    Node* p1 = head1->next;
    Node* p2 = head2;
    int counter = 1;
    while (p1 != nullptr && p2 != nullptr) {
        if (counter % 2 == 0) {
            tail->next = p1;
            p1 = p1->next;
        } else {
            tail->next = p2;
            p2 = p2->next;
        }
        tail = tail->next;
        counter += 1;
    }
    if (p1 == nullptr) {
        tail->next = p2;
    } else {
        tail->next = p1;
    }

    return head1;
}

Node* zipperLists3(Node* head1, Node* head2) {
    Node* tail = head1;
    Node* p1 = head1->next;
    Node* p2 = head2;
    int counter = 1;
    while (p1 != nullptr && p2 != nullptr) {
        if (counter % 2 == 0) {
            tail->next = p1;
            p1 = p1->next;
        } else {
            tail->next = p2;
            p2 = p2->next;
        }
        tail = tail->next;
        counter += 1;
    }
    if (p1 == nullptr) {
        tail->next = p2;
    } else {
        tail->next = p1;
    }

    return head1;
}

Node* zipperLists2(Node* head1, Node* head2) {
    if (head1 == nullptr || head2 == nullptr) {
        return head1 != nullptr ? head1 : head2;
    }

    Node* head1_next = head1->next;
    Node* head2_next = head2->next;

    head1->next = head2;
    if (head1_next != nullptr) {
        head2->next = head1_next;
    }
    zipperLists2(head1_next, head2_next);

    return head1;
}

Node* zipperLists1(Node* head1, Node* head2) {
    if (head1 == nullptr) {
        head1 = head2;
        head2 = nullptr;
    }
    Node* node1 = head1;
    Node* node2 = head2;
    Node* prev = new Node("-1");
    Node* sent = prev;
    prev->next = node1;
    while (node1 != nullptr && node2 != nullptr) {
        prev->next = node1;
        Node* node1_next = node1->next;
        node1->next = node2;
        prev = node2;
        node1 = node1_next;
        node2 = node2->next;
    }
    if (node1 != nullptr) {
        prev->next = node1;
    }

    return sent->next;
}

void run() {
    // this function behaves as `main()` for the 'run' command
    // you may sandbox in this function, but should not remove it
}
