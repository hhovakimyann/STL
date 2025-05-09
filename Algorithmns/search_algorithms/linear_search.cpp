#include <iostream>
#include <vector>
int linear_search(std::vector<int>& vec, int target) {
    for(int i = 0 ; i < vec.size(); i++) {
        if(vec[i] == target) {
            return i;
        }
    }
    return -1;
}

int main () {
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    int res = linear_search(vec,1);
    std::cout << res << std::endl;
}