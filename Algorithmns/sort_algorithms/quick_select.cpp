#include <iostream> 
#include <vector>

int quicksort(std::vector<int>& nums, int k, int left, int right) {
    int pivot = nums[right];
    int i = left;
    int j = right - 1;

    while(i <= j) {
        while(i <= j && nums[i] <= pivot ) {
            i++;
        }
        while(i <= j && nums[j] >= pivot) {
            j--;
        }
        if(i < j) {
            std::swap(nums[i], nums[j]);
        }
    }
    std::swap(nums[i], nums[right]);

    if(k == i) {return k;}
    else if(i < k) {return quicksort(nums,k,i + 1, right);}
    else return quicksort(nums,k,left, i - 1);
}

int quickselect(std::vector<int>&nums, int k) {
    return quicksort(nums,k - 1,0,nums.size() - 1);
}
int main () {
    std::vector<int> nums = {3, 2, 1, 5, 4};

    int k = 3;
    std::cout << quickselect(nums,k) << std::endl;

}