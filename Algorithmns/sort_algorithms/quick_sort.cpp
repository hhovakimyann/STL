#include <iostream>
#include <vector>

int partition(std::vector<int>& vec, int start, int end) {
    int i = start;
    int j = end - 1;
    int val = vec[end];

    while(i <= j) {
        while(i <= j && vec[j] >= val) {
            j--;
        }
        while(i <= j && vec[i] <= val) {
            i++;
        }
        if(i < j) {
            std::swap(vec[i],vec[j]);
        }
    }
    std::swap(vec[i],vec[end]);
    return i;
}

void quick_sort(std::vector<int>& vec, int start, int end) {
   if(start > end) return;
   int index = partition(vec,start,end);
   quick_sort(vec,start,index - 1);
   quick_sort(vec,index + 1, end);
   return;
}
int main () {
    std::vector<int> vec = {4,5,9,3,1,6,0,22,37,99};
    quick_sort(vec,0,vec.size() - 1);

    for(auto x : vec) {
        std::cout << x << " ";
    }
    std::cout <<  std::endl;
}