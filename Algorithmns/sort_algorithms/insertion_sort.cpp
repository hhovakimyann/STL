#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>& nums) {
    int index = 0;
    int value = 0;

    for(int i = 1; i < nums.size(); ++i) {
        index = i - 1;
        value = nums[i];
        while(index >= 0 && nums[index] > value) {
            nums[index + 1] = nums[index];
            --index ;
        }
        nums[index + 1] = value;
    }
}

int main () {
    std::vector<int> vec = {10,9,8,7,6,5,4,3,2,1,4};
    insertion_sort(vec);
    for(auto x : vec) {
        std::cout << " " << x;
    }
}