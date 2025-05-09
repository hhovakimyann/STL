#include <iostream>
#include <vector>

int bsr(std::vector<int>& vec, int target, int left, int right) {
    if(left <= right) {
        int mid = left + (right - left) / 2;
        if(vec[mid] == target) {
            return mid;
        } else if(vec[mid] < target) {
            return  bsr(vec, target, mid + 1, right);
        }else {
            return bsr(vec,target,left, mid - 1);
        }
    }
    return -1;
}

int main () {
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    int res = bsr(vec,11,0,vec.size() - 1);
    std::cout << res << std::endl;
}