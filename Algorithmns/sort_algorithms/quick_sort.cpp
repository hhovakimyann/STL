#include <iostream>
#include <vector>

int partition(std::vector<int>&vec, int left,int right) {
    int pivot = vec[right];
    int i = left;
    int j = right - 1;

    while(i <= j) {
        while(i <= j && vec[i] < pivot) {
            i++;
        }
        while(i <= j && vec[j] >= pivot) {
            j--;
        }
        if(i < j) {
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i], vec[right]);
    return i;
}
void quick_sort(std::vector<int>&nums, int left, int right) {
    if(left >= right) return;
    int index = partition(nums,left,right);

    quick_sort(nums,left,index - 1);
    quick_sort(nums,index + 1, right);
}
int main () {
    std::vector<int> vec = {4,5,9,3,1,6,0,22,37,99};
    quick_sort(vec,0,vec.size() - 1);

    for(auto x : vec) {
        std::cout << x << " ";
    }
    std::cout <<  std::endl;
}