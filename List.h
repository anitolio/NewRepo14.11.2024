#pragma once

class List {
private:
    class Node {
    public:
        int value;
        Node* prev;
        Node* next;

        Node(int value);
    };

    Node* head;
    Node* tail;

public:
    List();
    ~List();
    List(const List& other);
    List& operator=(const List& other);

    void push_back(int value);
    void push_front(int value);
    void pop_front();
    void pop_back();
    void reverse();
    void show() const;
    void clear();
};