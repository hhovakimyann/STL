#include "include.hpp"

int main() {
    Queue<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.pop();
    std::cout << s1.front() << std::endl;
    std::cout << "Size: " << s1.size() << "\n";
    Queue<int> s2 = {1, 2, 3};
    std::cout << "Size: " << s2.size() << "\n";
    s2 = s1;
    std::cout << "Size after assignment: " << s2.size() << "\n";
    Queue<int> s3(std::move(s1));
    std::cout << "Size after move: " << s3.size() << "\n";
    s3.swap(s2);
    std::cout << "Size after swap: " << s1.size() << "\n";
    std::cout << "Empty: " << s1.empty() << "\n";
    std::cout << "Equal: " << (s2 == s1) << "\n";
    std::cout << "Not Equal: " << (s2 != s1) << "\n";
    std::cout << "Less: " << (s2 < s1) << "\n";
    std::cout << "Less or Equal: " << (s2 <= s1) << "\n";
    std::cout << "Greater: " << (s2 > s1) << "\n";
    std::cout << "Greater or Equal: " << (s2 >= s1) << "\n";
    return 0;
}