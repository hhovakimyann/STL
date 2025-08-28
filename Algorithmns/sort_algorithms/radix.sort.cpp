#include <iostream>
#include <vector>

void countingSort(std::vector<int> &vec, int exp) {
    std::vector<int> output(vec.size());
    std::vector<int> counting(10);
    for(int i = 0; i < vec.size() ; i++) {
        counting[(vec[i] / exp) % 10]++;
    }

    for(int i = 1; i < 10 ; i++) {
        counting[i] += counting[i - 1];
    }

    for(int i = vec.size() - 1; i >= 0; i--) {
        output[counting[(vec[i] / exp) % 10] - 1] = vec[i];
        counting[(vec[i] / exp) % 10]--;
    }
    
    for(int i = 0; i < vec.size(); i++) {
        vec[i] = output[i];
    }
}
int getMax(std::vector<int>&vec, int size) {
    int max;
    for(int i = 0; i < size; i++) {
        max = std::max(max,vec[i]);
    }
    return max;
}

void radixSort(std::vector<int>&vec, int size) {
    int max = getMax(vec,size - 1);

    for(int i = 1; max / i > 0; i *= 10) {
        countingSort(vec,i);
    }
}

int main () {
    std::vector<int> vec  = {4, 5, 9, 3, 1, 6, 0, 22, 37, 99};
    radixSort(vec,vec.size());

    for(int x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}