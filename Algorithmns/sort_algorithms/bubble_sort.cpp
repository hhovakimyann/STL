#include <iostream>
#include <vector>


void bubble_sort(std::vector<int>& nums) {
    int size = nums.size() - 1;
    bool flag;
    for(int i = 0; i < size; i++) {
        flag = false;
        for(int j = 0; j < size - i ;j ++) {
            if(nums[j] > nums[j + 1]) {
                std::swap(nums[j], nums[j + 1]);
                flag = true; 
            }
        }
        if(!flag) {
            break;
        }
    }
}
int main () {
    std::vector<int> vec = {2,4,45,6,5,2,46,8,7,32,3,4,333};
    bubble_sort(vec);
    for(auto it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}