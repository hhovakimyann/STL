#include "include.hpp"

using namespace std;

void test_construction() {
    priority_queue<int, vector<int>, greater<int>> pq;
    assert(pq.empty());
    assert(pq.size() == 0);
    cout << "Construction test passed!" << endl;
}

void test_push_and_top() {
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(10);
    pq.push(5);
    pq.push(20);
    assert(pq.top() == 20);
    pq.push(1);
    assert(pq.top() == 20);
    cout << "Push and top test passed!" << endl;
}

void test_pop() {
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.pop();
    assert(pq.top() == 10);
    pq.pop();
    assert(pq.top() == 5);
    cout << "Pop test passed!" << endl;
}

void test_copy_assignment() {
    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(10);
    pq1.push(5);
    priority_queue<int, vector<int>, greater<int>> pq2 = pq1;
    assert(pq2.top() == 10);
    pq2.pop();
    assert(pq2.top() == 5);
    cout << "Copy assignment test passed!" << endl;
}

void test_move_assignment() {
    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(15);
    pq1.push(30);
    priority_queue<int, vector<int>, greater<int>> pq2 = std::move(pq1);
    assert(pq2.top() == 30);
    assert(pq1.empty());
    cout << "Move assignment test passed!" << endl;
}

void test_swap() {
    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(10);
    pq1.push(5);
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(20);
    pq2.push(15);
    pq1.swap(pq2);
    assert(pq1.top() == 20);
    assert(pq2.top() == 10);
    cout << "Swap test passed!" << endl;
}

int main() {
    test_construction();
    test_push_and_top();
    test_pop();
    test_copy_assignment();
    test_move_assignment();
    test_swap();


    priority_queue<int> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);
    pq.push(6);
    pq.push(7);
    pq.push(8);
    pq.push(9);    
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << std::endl;
    cout << "All tests passed successfully!" << endl;
    return 0;
}
