#include <iostream>
#include <climits>
#include <vector>
using namespace std;

///////////////////////////////////////////////////////////////////////
void selection_sort(vector<int>& arr) {

    for(int i = 0; i < arr.size(); i++) {
        int min_index = i;
        for(int j = i+1; j < arr.size(); j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}


//////////////////////////////////////////////////////////////////////////////

void insertion_sort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int x = i;
        for(int j = i - 1; j >= 0; --j, --x) {
            if(arr[x] < arr[j]) {
                int temp = arr[x];
                arr[x] = arr[j];
                arr[j] = temp;
            } 
            else {
                break;
            }
        }
    }
}


/////////////////////////////////////////////////////////////////////////////
void bubble_sort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////
void merge(vector<int>& arr, int start, int mid, int end) {
    vector<int> temp;
    int i = start, j = mid+1;

    while(i <= mid && j <= end) {
        if(arr[i] < arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }
    while(i <= mid) {
        temp.push_back(arr[i++]);
    }
    while(j <= end) {
        temp.push_back(arr[j++]);
    }
    for(int idx = 0; idx < temp.size(); idx++) {
        arr[idx + start] = temp[idx];
    }
}

void merge_sort(vector<int>& arr, int i, int j) {
    if(i < j) {
        int mid = i + (j-i)/2;
        merge_sort(arr, i, mid);
        merge_sort(arr, mid+1, j);

        merge(arr, i, mid, j);
    }
}

/////////////////////////////////////////////////////////////////////////
int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l - 1;
    int temp;
    for(int j = l; j < r; j++) {
        if(arr[j] < arr[r]) {
            i++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    return i + 1;
}

void quick_sort(int arr[], int l, int r) {
    if(l < r) {
        int mid = partition(arr, l, r);
        quick_sort(arr, l, mid - 1);
        quick_sort(arr, mid + 1, r);
    }
}

//////////////////////////////////////////////////////////////////////////
int main() {
    vector<int> nums = {49, 69, 29, 19, 199, 39, 9, 79};

    // selection_sort(arr);
    merge_sort(nums, 0, nums.size()-1);

    for(int num: nums) {
        cout << num << " "; 
    }
    return 0;
}