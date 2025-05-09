#include <iostream>
#include <vector>

int binary_search(std::vector<int>& vec, int target) {
    int start = 0;
    int end = vec.size() - 1;
    int mid = 0;
    while(start <= end) {
        mid = start + (end - start) / 2;
        if(vec[mid] == target) {
            return mid;
        }else if( vec[mid] < target) {
            start = mid + 1;
        }else {
            end = mid - 1;
        }
    }
    return -1;
}

int main () {
    std::vector <int> vec = {1,2,3,4,5,6,7,8,9,10};
    int res = binary_search(vec, 4);
    std::cout << res << std::endl;
}