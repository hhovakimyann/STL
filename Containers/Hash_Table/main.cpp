#include "include.hpp"

void test_constructors() {
    unordered_map<int, int> m1;
    assert(m1.size() == 0);
    assert(m1.empty());
    
    unordered_map<int, int> m2{{1, 10}, {2, 20}, {3, 30}};
    assert(m2.size() == 3);
    assert(m2.at(1) == 10);
    
    unordered_map<int, int> m3(m2);
    assert(m3.size() == 3);
    
    unordered_map<int, int> m4(std::move(m2));
    assert(m4.size() == 3);
    assert(m2.empty());
}

void test_assignment() {
    unordered_map<int, int> m1{{1, 10}, {2, 20}};
    unordered_map<int, int> m2;
    m2 = m1;
    assert(m2.size() == 2);
    assert(m1.size() == 2);

    m2 = std::move(m1);
    assert(m2.size() == 2);
    assert(m1.empty());
}

void test_insert_erase() {
    unordered_map<int, std::string> map;
    map.insert(1, "one");
    assert(map.size() == 1);
    assert(map.at(1) == "one");
    
    map.insert({{2, "two"}, {3, "three"}});
    assert(map.size() == 3);
    
    assert(map.erase(2) == 1);
    assert(map.size() == 2);
    assert(map.erase(99) == 0);
    
    map.clear();
    assert(map.empty());
}

void test_access() {
    unordered_map<int, int> map;
    map[4] = 40; 
    assert(map[4] == 40);
    map[4] = 400;
    assert(map.at(4) == 400);

    try {
        map.at(5);
        assert(false);
    } catch (const std::invalid_argument&) {}

    const auto& cmap = map;
    try {
        cmap.at(5);
        assert(false);
    } catch (const std::invalid_argument&) {}
}

void test_iterators() {
    unordered_map<int, int> map{{1, 10}, {2, 20}, {3, 30}};
    size_t count = 0;
    for (auto it = map.begin(); it != map.end(); it++) {
        ++count;
    }
    assert(count == 3);
    count = 0;
    const unordered_map<int,int> const_map{{1,10}, {2,20}, {3,30}};
    for (auto it = const_map.cbegin(); it != const_map.cend(); it++) {
        ++count;
    }
    assert(count == 3);
}

void test_rehash() {
    unordered_map<int, int> map;
    map.max_load_factors(0.5);
    for (int i = 0; i < 10; ++i) {
        map.insert(i, i*10);
    }
    assert(map.load_factor() <= 0.5);
}

void test_swap() {
    unordered_map<int, int> m1{{1, 10}}, m2{{2, 20}};
    m1.swap(m2);
    assert(m1.size() == 1);
    assert(m1.find(2) != m1.end());
    assert(m2.size() == 1);
    assert(m2.find(1) != m2.end());
}

void test_misc() {
    unordered_map<int, int> map;
    assert(map.max_size() == std::numeric_limits<size_t>::max());
    assert(map.hash_function()(42) == std::hash<int>{}(42));
}

int main() {
    try {
        
        test_constructors();
        test_assignment();
        test_insert_erase();
        test_access();
        test_iterators();
        test_rehash();
        test_swap();
        test_misc();
        std::cout << "All tests passed!\n";
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << '\n';
        return 1;
    }
    return 0;
}