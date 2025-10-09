#include <iostream>
#include <vector>
using namespace std;

int l_serach(vector<int>& arr, int num) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == num) {
            return i;
        }
    }
    return -1;
}

int b_search(vector<int>& arr, int num, int i, int j) {
    if(i < 0 || j > arr.size()-1 || i > arr.size()-1 || j < 0) {
        return - 1;
    }
    //int mid = (i+j)%2 == 0 ? (i+j)/2 : (i+j+1)/2;
    int mid = (i+j)/2;
    if(arr[mid] == num) {
        return mid;
    } else if(arr[mid] > num) {
        return b_search(arr, num, i, mid-1);
    } else {
        return b_search(arr, num, mid+1, j);
    }
}


int main() {
    vector<int> nums = { 1, 3, 4, 5, 8, 10, 14, 15, 17};
    cout << b_search(nums, 3, 0, nums.size()-1) << endl;
    cout << b_search(nums, 8, 0, nums.size()-1) << endl;
    cout << b_search(nums, 17, 0, nums.size()-1) << endl;
    cout << b_search(nums, 4, 0, nums.size()-1);
    
    return 0;
}