#include <iostream>
#include <vector>

void selection_sort(std::vector<int>& nums) {
    int size = nums.size() - 1;
    int min_index = 0;
    for(int i = 0; i < size; i++) {
        min_index = i;
        for(int j = i + 1; j < size; j++) {
            if(nums[j] < nums[min_index]) {
                min_index = j;
            }
        }
        std::swap(nums[i], nums[min_index]);
    }
}
int main () {
    std::vector<int> vec = {2,4,45,6,5,2,46,8,7,32,3,4,333};
    selection_sort(vec);
    for(auto it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}