#include "include.hpp"

void testConstructors() {
    // Default constructor
    List<int> list1;
    assert(list1.size() == 0);
    assert(list1.empty() == true);

    // Initializer list constructor
    List<int> list2{1, 2, 3, 4, 5};
    assert(list2.size() == 5);
    assert(list2[0] == 1);
    assert(list2[4] == 5);

    // Copy constructor
    List<int> list3(list2);
    assert(list3.size() == 5);
    assert(list3[0] == 1);
    assert(list3[4] == 5);

    // Move constructor
    List<int> list4(std::move(list2));
    assert(list4.size() == 5);
    assert(list2.size() == 0);
    assert(list2.empty() == true); // Check moved-from state
}

void testModifiers() {
    List<int> list;

    // push_back
    list.push_back(10);
    list.push_back(20);
    assert(list.size() == 2);
    assert(list[0] == 10);
    assert(list[1] == 20);

    // push_front
    list.push_front(5);
    assert(list.size() == 3);
    assert(list[0] == 5);
    assert(list[1] == 10);
    assert(list[2] == 20);

    // pop_front
    list.pop_front();
    assert(list.size() == 2);
    assert(list[0] == 10);
    assert(list[1] == 20);

    // pop_back
    list.pop_back();
    assert(list.size() == 1);
    assert(list[0] == 10);

    // erase
    list.push_back(30);
    list.push_back(40);
    list.erase(1);
    assert(list.size() == 2);
    assert(list[1] == 40);

    // insert
    list.insert(1, 25);
    assert(list.size() == 3);
    assert(list[1] == 25);
}

void testElementAccess() {
    List<int> list{1, 2, 3, 4, 5};

    // Testing front and back
    assert(list.front() == 1);
    assert(list.back() == 5);

    // Testing operator[]
    assert(list[0] == 1);
    assert(list[2] == 3);
    assert(list[4] == 5);

    // Test out of range
    try {
        list[5];
        assert(false); // Should not reach here
    } catch (const std::out_of_range&) {
        assert(true);
    }
}

void testClearAndEmpty() {
    List<int> list{1, 2, 3, 4};

    list.clear();
    assert(list.size() == 0);
    assert(list.empty() == true);
}

void testReverse() {
    List<int> list{1, 2, 3, 4, 5};
    list.reverse();
    assert(list[0] == 5);
    assert(list[4] == 1);
}

void testRemove() {
    List<int> list{1, 2, 3, 2, 4, 2};

    list.remove(2);
    assert(list.size() == 3);
    assert(list.find(2) == false);
    assert(list[0] == 1);
    assert(list[1] == 3);
    assert(list[2] == 4);
}

void testSwap() {
    List<int> list1{1, 2, 3};
    List<int> list2{4, 5, 6, 7};

    list1.swap(list2);
    assert(list1.size() == 4);
    assert(list2.size() == 3);
    assert(list1[0] == 4);
    assert(list2[0] == 1);
}

int main() {
    testConstructors();
    testModifiers();
    testElementAccess();
    testClearAndEmpty();
    testReverse();
    testRemove();
    testSwap();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}