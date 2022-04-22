#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "linearlist.h"

template<class T>
class ArrayList : public LinearList<T> {
    private:
        T* array;
        int arrayLength;
        int lastIndex;

        auto resizeArray(bool) -> void;

    public:
        ArrayList(const int&);
        ~ArrayList();

        auto isEmpty(void) const -> bool;
        auto prepend(const T&) -> void;
        auto append(const T&) -> void;
        auto size(void) const -> int;
        auto printArray() -> void;
        auto indexOf(const T&) const -> int;
        auto remove(int) -> void;
        auto insert(const T&, int) -> void;
        auto countingSort(int) -> void;
        auto selectionSort() -> void;
        auto bubbleSort() -> void;
        auto insertionSort() -> void;
};

#include "arraylist.inl"
#endif //#ifndef ARRAYLIST_H