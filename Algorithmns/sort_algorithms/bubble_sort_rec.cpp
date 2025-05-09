#include <iostream>
#include <vector>

void bubble_sort_rec(std::vector<int>& nums, int size) {

    if(size == 0) return;

    bool flag = false;

    for(int j = 0; j < size - 1; j++) {
        if(nums[j] > nums[j + 1]) {
            flag = true;
            std::swap(nums[j],nums[j + 1]);
        }
    }
    if(flag == false) {
        return;
    }
    bubble_sort_rec(nums, size - 1);
}
int main () {
    std::vector<int> vec = {2,4,45,6,5,2,46,8,7,32,3,4,333};
    bubble_sort_rec(vec,vec.size());
    for(auto it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}