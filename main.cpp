#include <iostream>
#include "arraylist.h"

int main() {
    ArrayList<int> list(3);
    list.append(3);
    list.append(0);
    list.append(7);
    list.append(2);
    list.append(4);
    list.append(6);
    list.append(2);

    list.insertionSort();

    list.printArray();
}