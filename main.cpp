#include <iostream>
#include <string>
#include "Heap.h"

int main() {
    Heap<int, 10> intHeap;
    intHeap.push(5);
    intHeap.push(1);
    intHeap.push(10);
    intHeap.push(3);

    std::cout << "Целые числа:\n";
    while (!intHeap.empty()) {
        std::cout << intHeap.pop() << " ";
    }
    std::cout << "\n\n";

    Heap<std::string, 5> colorHeap;
    colorHeap.push("green");
    colorHeap.push("red");

    std::cout << "Цвета:\n";
    while (!colorHeap.empty()) {
        std::cout << colorHeap.pop() << " ";
    }
    std::cout << "\n";

    return 0;
}
