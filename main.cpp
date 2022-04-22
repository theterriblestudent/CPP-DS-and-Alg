#include <iostream>
#include <stdexcept>
#include "linkedlist.h"

int main() {
    int list[] = {2, 6, 8, 2, 9, 6, 8, 10, 2, 9};
    LinkedList<int> myList(list, 10);
    // myList.forEach([](int element) -> void {std::cout << element << std::endl;});
    myList.binSort(10);
    myList.forEach([](int element) -> void {std::cout << element << std::endl;});
    return 0;
}