#include <iostream>
#include <vector>

void heapify(std::vector<int>& vec, int size, int index) {
    int i = index * 2;
    int j = index * 2 + 1;
    int largest = index;

    if(i < size && vec[i] > vec[largest]) {
        largest = i;
    }

    if(j < size && vec[j] > vec[largest]) {
        largest = j;
    }

    if(largest != index) {
        std::swap(vec[largest],vec[index]);
        heapify(vec,size,largest);
    }
}
void heap_sort(std::vector<int>& vec) {
    int size = vec.size();
    for(int i = size / 2 - 1; i >= 0; --i) {
        heapify(vec,size,i);
    }

    for(int i = size - 1; i >= 0; --i) {
        std::swap(vec[0],vec[i]);
        heapify(vec,i,0);
    }
}
int main () {
    std::vector<int> vec = { 9, 4, 3,1,8, 10, 2, 5 };
    heap_sort(vec);
    for(int x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}