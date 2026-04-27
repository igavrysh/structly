//
// Created by new on 4/27/26.
//

#include <string>
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

string middleValue(Node* head) {
    Node* senti = new Node("-1");
    senti->next = head;
    Node *fast = senti;
    Node *slow = senti;
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
        if (fast!= nullptr) {
            fast = fast->next;
        }
    }
    return slow->val;
}
