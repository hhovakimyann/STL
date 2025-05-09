#include <iostream>
#include <vector>
#include <cstdlib>


int partition(std::vector<int> &vec, int left, int right) {
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
void quickSort(std::vector<int>&vec, int left, int right) {
    if(left >= right) return;
    int index = partition(vec,left,right);
    quickSort(vec,left,index - 1);
    quickSort(vec,index + 1, right);
}
void quickSortRandom(std::vector<int>& vec, int left, int right) {
    if(left >= right) return;
    int randomIndex = left + rand() % (right - left + 1);
    std::swap(vec[randomIndex], vec[right]);
    for(int x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    quickSort(vec,left,right);
}
int main ( ) {
    std::vector<int> vec = {4,5,9,3,1,6,0,22,37,99};
    quickSortRandom(vec,0,vec.size() - 1);

    for(int x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}