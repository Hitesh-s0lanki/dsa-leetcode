#include <iostream>
#include <vector>

using namespace std;

int countMajoritySubarrays(vector<int>& nums, int target) {
    int n = nums.size();
    int count = 0;

    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = i; j < n; j++){
            if(nums[j] == target) cnt++;
            if (cnt > (j - i + 1)/2) count++;
        }
    }

    return count;
}

int main() {

    vector<int> nums = {1,2,2,3};
    int target = 2;

    cout<<countMajoritySubarrays(nums, target);

    return 0;
}