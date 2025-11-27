#include <iostream>
#include "MyArray.h"

int main() {
    MyArray arr1(3);
    for (int i = 0; i < 3; ++i) {
        arr1.setElement(i, i + 1);
    }

    MyArray arr2(2);
    for (int i = 0; i < 2; ++i) {
        arr2.setElement(i, i + 4);
    }

    MyArray arr3 = arr1.merge(arr2);
    std::cout << "Merge result size: " << arr3.getSize() << std::endl;
    for (int i = 0; i < arr3.getSize(); ++i) {
        std::cout << arr3.getElement(i) << " ";
    }
    std::cout << std::endl;

    MyArray sum = arr1.add(arr2);
    std::cout << "Add result size: " << sum.getSize() << std::endl;
    for (int i = 0; i < sum.getSize(); ++i) {
        std::cout << sum.getElement(i) << " ";
    }
    std::cout << std::endl;

    MyArray diff = arr1.subtract(arr2);
    std::cout << "Subtract result size: " << diff.getSize() << std::endl;
    for (int i = 0; i < diff.getSize(); ++i) {
        std::cout << diff.getElement(i) << " ";
    }
    std::cout << std::endl;

    MyArray prod = arr1.multiply(arr2);
    std::cout << "Multiply result size: " << prod.getSize() << std::endl;
    for (int i = 0; i < prod.getSize(); ++i) {
        std::cout << prod.getElement(i) << " ";
    }
    std::cout << std::endl;

    MyArray quot = arr1.divide(arr2);
    std::cout << "Divide result size: " << quot.getSize() << std::endl;
    for (int i = 0; i < quot.getSize(); ++i) {
        std::cout << quot.getElement(i) << " ";
    }
    std::cout << std::endl;

    MyArray arr4 = arr1;
    std::cout << "Copy constructor result size: " << arr4.getSize() << std::endl;
    for (int i = 0; i < arr4.getSize(); ++i) {
        std::cout << arr4.getElement(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}