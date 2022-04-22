#include <stdexcept>
#include <iostream>
#include "linkedlist.h"

//Creating a linked list from an array (Constructor)
template<typename T>
LinkedList<T>::LinkedList(T* initArray, int arrayLength) : LinkedList() {
    for (int i = 0; i < arrayLength; i++) {
        if(i == 0) {
            headNode = createNode(initArray[i]);
            listLength++;
        }else {
            tempNode = headNode;
            while(tempNode->nextNode) {tempNode = tempNode->nextNode;}
            tempNode->nextNode = createNode(initArray[i]);
            listLength++;
        }
    }
}

template<typename T>
LinkedList<T>::LinkedList() {
    headNode = nullptr;
    tempNode = nullptr;
    listLength = 0;
}

template<typename T>
auto LinkedList<T>::createNode(T element, Node* nextNode) {
    Node* _tempNode = new Node;
    _tempNode->nextNode = nextNode;
    _tempNode->data = element;
    return _tempNode;
    
}

template <typename T>
void LinkedList<T>::clearList() {
    while (headNode) {
        tempNode = headNode->nextNode;
        delete headNode;
        headNode = tempNode;
    }
    listLength = 0;
}

template<typename T>
LinkedList<T>::~LinkedList() {clearList();}

template<typename T>
auto LinkedList<T>::forEach(void (*callback)(T element), int bound) {
    tempNode = headNode;
    if (bound == -1) bound = listLength;
    int _iterator = 1;
    while(tempNode->nextNode && _iterator < bound) {
        if(callback)
            callback(tempNode->data);
        tempNode = tempNode->nextNode;
        _iterator++;
    }
    if (callback)
        callback(tempNode->data);
}

template<typename T>
void LinkedList<T>::append(T element) {
    if (headNode) {
        forEach();
        tempNode->nextNode = createNode(element);
    }else headNode = createNode(element);
    listLength++;
}

template<typename T>
void LinkedList<T>::prepend(T element) {
    tempNode = createNode(element, headNode);
    headNode = tempNode;
    listLength++;
}

template<typename T>
void LinkedList<T>::insert(T element, int index) {
    if (index == 1) {
        prepend(element);
        listLength++;
        return;
    }
    if (index == listLength + 1) {
        append(element);
        return;
    }
    if (index > listLength + 1) {
         throw "List Index Out Of Bounds!";
         return;
    }
    forEach(nullptr, index - 1);
    Node* newNode = createNode(element, tempNode->nextNode);
    tempNode->nextNode = newNode;
    listLength++;
}

template<typename T>
void LinkedList<T>::remove(int index) {
    if(index > listLength) throw "List index out of bounds!";
    if (index == 1) {
        Node* deletedNode = headNode;
        headNode = headNode->nextNode;
        delete deletedNode;
        listLength--;
        return;
    }
    forEach(nullptr, index -1);
    Node* deletedNode = tempNode->nextNode;
    tempNode->nextNode = deletedNode->nextNode;
    delete deletedNode;
    listLength--;
}

template<typename T>
T& LinkedList<T>::operator[](int index) {
    if (index >= listLength || index < 0)
        throw std::out_of_range("List index out of bounds.");
    forEach(nullptr, index + 1);
    return tempNode->data;
}

//Algorithms
//Reversing algorithms
template<typename T>
void LinkedList<T>::reverse() {
   tempNode = headNode;
   Node *previousNode, *nextNode;
   previousNode = nullptr;
   while (tempNode->nextNode) {
       nextNode = tempNode->nextNode;
       tempNode->nextNode = previousNode;
       previousNode = tempNode;
       tempNode = nextNode;
   }
   tempNode->nextNode = previousNode;
   headNode = tempNode;
}

template<typename T>
void LinkedList<T>::reverse_recursion() {
    recursion(headNode); //Passing headNode as an arugument because for recursion to work, variables should be stores locally;
}

template<typename T>
void LinkedList<T>::recursion(Node* tempNode) {
    if (!tempNode->nextNode) {
        headNode = tempNode;
        return;
    }
    recursion(tempNode->nextNode);
    tempNode->nextNode->nextNode = tempNode;
    tempNode->nextNode = nullptr;
    return;
}

//Sorting algorithms
template<typename T>
void LinkedList<T>::binSort(int range) {
    Node **top = new Node* [range + 1];
    Node **bottom = new Node* [range + 1];

    for (int i = 0; i <= range; i++) 
        bottom[i] = nullptr;
    
    tempNode = headNode;
    
    while (tempNode) {
        if (!bottom[tempNode->data])
            bottom[tempNode->data] = top[tempNode->data] = tempNode;
        else {
            top[tempNode->data]->nextNode = tempNode;
            top[tempNode->data] = top[tempNode->data]->nextNode;
        }
        tempNode = tempNode->nextNode;
    }

    headNode = nullptr;
    tempNode = nullptr;

    for (int i = 0; i <= range; i++) {
        if (bottom[i]) {
            if (!headNode)
                headNode = bottom[i];
            if (tempNode)
                tempNode->nextNode = bottom[i];
            tempNode = top[i];
        }
    }

    delete[] top;
    delete[] bottom;
}