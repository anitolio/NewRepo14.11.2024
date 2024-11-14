#include <iostream>  
#include "list.h"  

List::Node::Node(int value) : value(value), prev(nullptr), next(nullptr) {}

List::List() : head(nullptr), tail(nullptr) {}

List::~List()
{
    clear();
}

List::List(const List& other) : head(nullptr), tail(nullptr) {
    Node* current = other.head;
    while (current) {
        push_back(current->value);
        current = current->next;
    }
}

List& List::operator=(const List& other) {
    if (this != &other) {
        clear();
        Node* current = other.head;
        while (current) {
            push_back(current->value);
            current = current->next;
        }
    }
    return *this;
}

void List::push_back(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void List::push_front(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void List::pop_front() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }
    delete temp;
}

void List::pop_back() {
    if (!tail) return;
    Node* temp = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    }
    else {
        head = nullptr;
    }
    delete temp;
}

void List::reverse()
{
    Node* current = head;
    Node* temp = nullptr;
    tail = head;

    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp) {
        head = temp->prev;
    }
}

void List::show() const {
    Node* current = head;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void List::clear() {
    while (head) {
        pop_front();
    }

}