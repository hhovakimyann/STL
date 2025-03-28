#include <iostream>
#include "array.hpp"

int main() {
    Array<int, 5> arr1 = {1, 2, 3, 4, 5};
    Array<int, 5> arr2 = {1, 2, 3, 4, 6};

    std::cout << std::boolalpha;
    std::cout << "Comparison Tests:\n";
    std::cout << "arr1 == arr2: " << (arr1 == arr2) << "\n"; // false
    std::cout << "arr1 != arr2: " << (arr1 != arr2) << "\n"; // true
    std::cout << "arr1 <  arr2: " << (arr1 < arr2) << "\n";  // true
    std::cout << "arr1 >  arr2: " << (arr1 > arr2) << "\n";  // false
    std::cout << "arr1 <= arr2: " << (arr1 <= arr2) << "\n"; // true
    std::cout << "arr1 >= arr2: " << (arr1 >= arr2) << "\n"; // false

    std::cout << "\nElement Access Tests:\n";
    std::cout << "arr1[0]: " << arr1[0] << "\n";           // 1
    std::cout << "arr1.front(): " << arr1.front() << "\n";  // 1
    std::cout << "arr1.back(): " << arr1.back() << "\n";    // 5

    try {
        std::cout << "arr1.at(4): " << arr1.at(4) << "\n";   // 5
        std::cout << "arr1.at(5): ";
        arr1.at(5);
    } catch (const std::out_of_range& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    arr1.fill(10);
    arr2.swap(arr1);

    std::cout << "\nAfter Fill and Swap:\n";
    std::cout << "arr1[0]: " << arr1[0] << "\n"; 
    std::cout << "arr2[0]: " << arr2[0] << "\n"; 

    std::cout << "\nIterator Test:\n";
    std::cout << "arr2 elements: ";
    for (auto it = arr2.begin(); it != arr2.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    return 0;
}