#include <iostream>
#include <vector>


void merge(std::vector<int>& vec, int start, int mid, int end) {
    int s1 = start;
    int e1 = mid;
    int s2 = mid + 1;
    int e2 = end;

    std::vector<int> temp(end - start + 1);
    int k = 0;
    while(s1 <= e1 && s2 <= e2) {
        if(vec[s1] < vec[s2]) {
            temp[k] = vec[s1];
            s1++;
        }else {
            temp[k] = vec[s2];
            s2++;
        }
        k++;
    }

    while(s1 <= e1) {
        temp[k++] = vec[s1++];
    }

    while(s2 <= e2) {
        temp[k++] = vec[s2++];
    }

    for(int i = 0; i < temp.size(); i++) {
        vec[start + i ] = temp[i];
    }
}
void mergeSort(std::vector<int>& vec, int start, int end) {
    if(start >=  end) return;
    int mid = start + (end - start) / 2;

    mergeSort(vec,start,mid);
    mergeSort(vec,mid + 1, end);
    merge(vec,start,mid,end);
}
int main () {
    std::vector<int> vec = {223,4,2,6,90,24,231,1,344,5,6};
    mergeSort(vec,0,vec.size() - 1);

    for(int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}