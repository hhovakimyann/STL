#include "include.hpp"
#include <iostream>

int main() {
    using namespace my_std;

    Vector<int> vec1;
    std::cout << "vec1 created. Size: " << vec1.size() << std::endl;

    Vector<int> vec2(5);
    std::cout << "vec2 created with size 5. Size: " << vec2.size() << std::endl;

    Vector<int> vec3(5, 10);
    std::cout << "vec3 created with size 5 and filled with 10s." << std::endl;

    Vector<int> vec4 = {1, 2, 3, 4, 5};
    std::cout << "vec4 created from initializer list. Elements: ";
    for (auto it = vec4.begin(); it != vec4.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    Vector<int> vec5(vec4);
    std::cout << "vec5 copied from vec4. Elements: ";
    for (auto it = vec5.begin(); it != vec5.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    vec1.push_back(100);
    vec1.push_back(200);
    vec1.push_back(300);
    std::cout << "vec1 after push_back: ";
    for (auto it = vec1.begin(); it != vec1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    vec1.insert(1, 2, 500);
    std::cout << "vec1 after insert at index 1, twice 500: ";
    for (auto it = vec1.begin(); it != vec1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    vec1.erase(2);
    std::cout << "vec1 after erasing index 2: ";
    for (auto it = vec1.begin(); it != vec1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    vec1.resize(10, 20);
    std::cout << "vec1 after resizing to 10 elements with default value 20: ";
    for (auto it = vec1.begin(); it != vec1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    vec1.swap(vec2);
    std::cout << "vec1 after swapping with vec2: ";
    for (auto it = vec1.begin(); it != vec1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    Vector<int> vec6 = vec4 + vec2;
    std::cout << "vec6 after concatenation (vec4 + vec2): ";
    for (auto it = vec6.begin(); it != vec6.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    vec1.clear();
    std::cout << "vec1 after clear: " << (vec1.empty() ? "Empty" : "Not Empty") << std::endl;

    if (vec4 == vec5) {
        std::cout << "vec4 and vec5 are equal" << std::endl;
    }

    if (vec2 < vec3) {
        std::cout << "vec2 is less than vec3" << std::endl;
    }
    return 0;
}
