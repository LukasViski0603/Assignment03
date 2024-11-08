#pragma once

#include <stdexcept>

template <typename T>
class Queue {
private:
    // Node structure for linked list implementation
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* front_ptr;  // Points to front of queue
    Node* rear_ptr;   // Points to rear of queue
    int count;        // Keeps track of number of elements

public:
    Queue() : front_ptr(nullptr), rear_ptr(nullptr), count(0) {}
    ~Queue();

    // Core operations
    void push(const T& value);
    void pop();
    T& front();
    const T& front() const;
    bool empty() const;
    int size() const;

    // Assignment-specific operation
    void move_to_rear();
};

// Including template implementations in header due to template requirements
template <typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
void Queue<T>::push(const T& value) {
    Node* new_node = new Node(value);
    if (empty()) {
        front_ptr = rear_ptr = new_node;
    }
    else {
        rear_ptr->next = new_node;
        rear_ptr = new_node;
    }
    count++;
}

template <typename T>
void Queue<T>::pop() {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    Node* temp = front_ptr;
    front_ptr = front_ptr->next;
    delete temp;
    count--;
    if (count == 0) {
        rear_ptr = nullptr;
    }
}

template <typename T>
T& Queue<T>::front() {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    return front_ptr->data;
}

template <typename T>
const T& Queue<T>::front() const {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    return front_ptr->data;
}

template <typename T>
bool Queue<T>::empty() const {
    return count == 0;
}

template <typename T>
int Queue<T>::size() const {
    return count;
}

template <typename T>
void Queue<T>::move_to_rear() {
    if (empty() || size() == 1) {
        return;  // Nothing to move
    }
    T front_value = front();
    pop();
    push(front_value);
}