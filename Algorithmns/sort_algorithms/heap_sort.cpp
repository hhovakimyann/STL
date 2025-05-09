#include <iostream>
#include <vector>


void heapify(std::vector<int>& vec, int size, int maxindex) {
    int largest_index = maxindex;

    int i = maxindex * 2 + 1;
    int j = maxindex * 2 + 2;

    if(i < size && vec[i] > vec[largest_index]) {
        largest_index = i;
    }

    if(j < size && vec[j] > vec[largest_index]) {
        largest_index = j;
    }

    if( largest_index != maxindex) {
        std::swap(vec[maxindex], vec[largest_index]);
        heapify(vec,size,largest_index);
    }
}
void heap_sort(std::vector<int>& vec) {
    int size = vec.size();

    for(int i = size / 2 - 1; i >= 0; i--) {
        heapify(vec,size,i);
    }

    for(int i = size - 1; i > 0; i--) {
        std::swap(vec[0], vec[i]);
        heapify(vec,i,0);
    }
}
int main () {
    std::vector<int> vec = { 9, 4, 3, 8, 10, 2, 5 };
    heap_sort(vec);
    for(int x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}