#include <iostream>
#include "List.h"

int main()
{
    List list;
    list.push_back(10);
    list.push_back(1);
    list.push_back(-5);
    list.push_front(12);
    std::cout << "Enter elements: ";
    list.show();

    list.reverse();
    std::cout << "Enter reversing: ";
    list.show();

    list.pop_back();
    std::cout << "Enter popping from back: ";
    list.show();

    list.pop_front();
    std::cout << "Enter after popping from front: ";
    list.show();

    List copiedList = list;
    std::cout << "Enter copied list: ";
    copiedList.show();

    list.push_back(4);
    std::cout << "Enter adding other items: ";
    list.show();
    std::cout << "Enter code without changes: ";
    copiedList.show();

    list.clear();
    std::cout << "Enter original cleaning: ";
    list.show();

    return 0;
}