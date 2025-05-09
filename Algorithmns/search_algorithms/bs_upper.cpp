#include <iostream>
#include <vector>


int upper_binary_search(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    int mid = 0;
    int tmp = - 1;

    while(left <= right) {
        mid = left + (right - left) / 2;
        if(nums[mid] == target) {
            tmp = mid;
            left = mid + 1;
        }else if(nums[mid] < target) {
            left = mid + 1;
        }else {
            right = mid - 1;
        }
    }
    return tmp;
}
int main () {

    std::vector<int> vec = {1,2,3,3,3,5,6,7,8,9,10};
    std::cout << upper_binary_search(vec,3) << std::endl;
}
