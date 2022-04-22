#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

//Template class for Linked List
template<typename T>
class LinkedList {
    struct Node {
        T data;
        Node* nextNode;
    };
    int listLength; 
    Node* headNode;
    Node* tempNode;
    auto createNode(T, Node* nextNode = nullptr);
    auto recursion(Node*) -> void;

    public:
        LinkedList(T*, int);
        LinkedList();
        ~LinkedList();

        auto forEach(void (*callback)(T element) = nullptr, int bound = -1);
        auto clearList() -> void;
        auto append(T element) -> void;
        auto prepend(T element) -> void;
        auto insert(T element, int index) -> void;
        auto remove(int index) -> void;
        auto operator[](int index) -> T&;
        auto reverse() -> void;
        auto reverse_recursion() -> void;
        auto binSort(int) -> void;

};

#include "linkedlist.inl"
#endif 