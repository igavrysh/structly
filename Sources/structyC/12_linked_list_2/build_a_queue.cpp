//
//  build_a_queue.cpp
//  MyCLI
//
//  Created by new on 3/22/26.
//

#include <stdexcept>

template <class T> class Node {
  public:
    T val;
    Node* next;

    Node() : next(nullptr) {}

    Node(T initialVal) {
      val = initialVal;
      next = nullptr;
    }
};

template <class T> class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int getSize() {
        return size;
    }

    void enqueue(T val) {
        Node<T> *node = new Node(val);
        if (head == nullptr) {
            tail = node;
            head = node;
            size = 1;
            return;
        }

        tail->next = node;
        tail = node;
        size++;
    }

    T dequeue() {
        if (this->size == 0) {
            throw std::runtime_error("queue is empty!");
        }

        Node<T>* node = this->head;
        head = node->next;
        size--;

        return node->val;
    }
};

