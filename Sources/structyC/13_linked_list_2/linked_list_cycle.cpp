//
// Created by new on 4/27/26.
//
#include <string>
#include <memory>
using namespace std;

class Node {
public:
     string val;
    Node* next;

    Node(string initialVal) {
        val = initialVal;
        next = nullptr;
    }
};

bool linkedListCycle(Node* head) {
    auto senti = std::make_unique<Node>("-1");
    senti->next = head;
    Node* fast = senti.get();
    Node* slow = senti.get();
    while (fast != nullptr
        && slow != nullptr /* just to silence warning cannot be null */) {
        slow = slow -> next;
        fast = fast -> next;
        if (fast != nullptr) {
            fast = fast -> next;
        }

        if (slow != nullptr && slow == fast) {
            return true;
        }
    }

    return false;
}