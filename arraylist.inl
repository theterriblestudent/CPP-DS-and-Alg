#include <iostream>
#include <math.h>
#include <stdexcept>
#include "arraylist.h"

template<class T>
ArrayList<T>::ArrayList(const int& initialCapacity) {
    if (initialCapacity <= 0) throw "Invalid size!";
    array = new T[initialCapacity];
    arrayLength = initialCapacity;
    lastIndex = -1;
}

template<class T>
ArrayList<T>::~ArrayList() {delete[] array;}

template<class T>
void ArrayList<T>::resizeArray(bool extend) {
    arrayLength = extend ? std::ceil(arrayLength * 1.5) : std::ceil(arrayLength/2);
    T* newArray = new T[arrayLength];
    for (int i = 0; i <= lastIndex; i++)
        newArray[i] = array[i];
    delete[] array;
    array = newArray;
}


template<class T>
bool ArrayList<T>::isEmpty(void) const {return lastIndex == -1;}

template<class T>
void ArrayList<T>::prepend(const T& data) {
    T prevElement, currentElement;
    if (++lastIndex == arrayLength)
        resizeArray(true);
    for (int i = lastIndex; i > 0; i--)
        array[i] = array[i - 1];
    array[0] = data;
}

template<class T>
void ArrayList<T>::append(const T& data){
    if (++lastIndex == arrayLength)
        resizeArray(true);
    array[lastIndex] = data;
}

template<class T>
int ArrayList<T>::size(void) const { return lastIndex + 1; }

template<class T>
int ArrayList<T>::indexOf(const T& data) const {
    for (int i = 0; i <= lastIndex; i++)
        if (array[i] == data) return i;
    return -1;
}

template<class T>
void ArrayList<T>::printArray() {
    for (int i = 0; i <= lastIndex; i++) {
        std::cout << array[i] << std::endl;
    }
}

template<class T>
void ArrayList<T>::remove(int index) {
    if (index < 0 || index > lastIndex)
        throw std::range_error("Array Index Out Of Bounds!");
    if (--lastIndex <= arrayLength/4)
        resizeArray(false);
    for (int i = index; i <= lastIndex; i++) 
        array[i] = array[i + 1];
}

template<class T>
void ArrayList<T>::insert(const T& element, int index) {
    if (index < 0 || index > lastIndex)
        throw std::range_error("Array Index Out Of Bounds!");
    if (++lastIndex == arrayLength)
        resizeArray(true);
    for (int i = lastIndex; i > index; i--)
        array[i] = array[i - 1];
    array[index] = element;
}

template<class T>
void ArrayList<T>::countingSort(int maxElement) {
    int range = maxElement + 1;
    T rangeArray[range];

    for (int i = 0; i < range; i++) 
        rangeArray[i] = 0;
    for (int i = 0; i <= lastIndex; i++) 
        rangeArray[array[i]]++;
    for (int i = 1; i < range; i++)
        rangeArray[i] = rangeArray[i] + rangeArray[i - 1];

    T* newArray = new T[arrayLength];

    for (int i = lastIndex; i >= 0; i--) 
        newArray[--rangeArray[array[i]]] = array[i];
    
    delete[] array;
    array = newArray;
}

template<class T>
void ArrayList<T>::selectionSort() {
    int leastElementIndex = 0;
    T tempElement;
    for (int i = 0; i < lastIndex; i++) {
        for (int j = i; j <= lastIndex; j++) {
            if(array[j] <= array[leastElementIndex])
                leastElementIndex = j;
        }
        tempElement = array[i];
        array[i] = array[leastElementIndex];
        array[leastElementIndex] = tempElement;
    }
}

template<class T>
void ArrayList<T>::bubbleSort() {
    T tempElement;
    for(int i = 0; i <= lastIndex; i++) {
        for (int j = 0; j < lastIndex - i; j++) {
            if(array[j] > array[j + 1]) {
                tempElement = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tempElement;
            }
        }
    }
}

template<class T>
void ArrayList<T>::insertionSort() {
    T tempElement;
    for(int i = lastIndex; i >= 0; i--) {
        tempElement = array[i];
        for (int j = i - 1; j >= 0; j--) {
            if(tempElement < array[j]) 
                array[i] = array[j];
            else 
                array[j] = tempElement;
        }
    }
}