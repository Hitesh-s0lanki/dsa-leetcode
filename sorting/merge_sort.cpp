#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> ans){
    for(int val:ans){
        cout<<val<<", ";
    }
    cout<<endl;
}

void merge(vector<int>& nums, int start, int mid, int end){
    vector<int> left;
    vector<int> right;

    //copy vale 
    for(int i = start; i <= mid; i++)
        left.push_back(nums[i]);
    for(int i = mid + 1; i <= end; i++)
        right.push_back(nums[i]);

    // print(left);
    // print(right);

    int i = 0;
    int j = 0;
    int k = start;
    while(i < left.size() && j < right.size()){
        if(left[i] > right[j]){
            nums[k++] = right[j++];
        }else{
            nums[k++] = left[i++];
        }
    }

    // remaining
    while(i < left.size()){
        nums[k++] = left[i++];
    }
    while(j < right.size()){
        nums[k++] = right[j++];
    }
}

void merge_sort(vector<int>& nums, int start, int end){
    if(start >= end) return;

    int mid = start + (end - start)/2;

    // left merge
    merge_sort(nums, start, mid);

    // right merge
    merge_sort(nums, mid + 1, end);

    merge(nums, start, mid, end);
}

int main() {

    vector<int> nums = {3, 4, 1, 2, 9, 0, 10};

    merge_sort(nums, 0, nums.size() - 1);

    print(nums);

    return 0;
}