//
// Created by new on 4/27/26.
//

#include <string>
#include <vector>
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

Node* createLinkedList(vector<string> values) {
    Node* dummy = new Node("abc");
    Node* prev = dummy;
    for (int i = 0; i < values.size(); i++) {
        prev->next = new Node(values[i]);
        prev = prev->next;
    }
    return dummy->next;
}
