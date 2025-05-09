#include <iostream>
#include <vector>

std::vector<int> counting_sort(std::vector<int>& vec) {
    int size = vec.size();
    int max = 0;
    for(int i = 0; i < size; i++) {
        max = std::max(max,vec[i]);
    }

    std::vector<int> counting(max);
    for(int i = 0; i < size; i++) {
        counting[vec[i]]++;
    }

    for(int i = 1; i <= max; i++) {
        counting[i] += counting[i - 1];
    }

    std::vector<int> output(size);
    for(int i = size - 1; i >= 0; i--) {
        output[counting[vec[i]] - 1] = vec[i];
        counting[vec[i]]--;
    }
    return output;
}
int main () {
    std::vector<int> vec = {4, 3, 12, 1, 5, 5, 3, 9 };
    std::vector<int> res = counting_sort(vec);
    for(int x : res) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}