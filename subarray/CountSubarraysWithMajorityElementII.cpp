// O(n log n)

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> ans){
    for(int val:ans){
        cout<<val<<", ";
    }
    cout<<endl;
}

long long merge(vector<int>& nums, int start, int mid, int end){

    long long count = 0;
    vector<int> left;
    vector<int> right;

    //copy vale 
    for(int i = start; i <= mid; i++)
        left.push_back(nums[i]);
    for(int i = mid + 1; i <= end; i++)
        right.push_back(nums[i]);

    // check for the majority by comparing left[i] > right[j] 
    int pointer = 0;
    for (int i = 0; i < left.size(); i++){
        while(pointer < right.size() && left[i] >= right[pointer]){
            pointer++;
        }
        count += right.size() - pointer;
    }

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

    return count;
}

long long merge_sort(vector<int>& nums, int start, int end){
    long long count = 0; 
    if(start >= end) return count;

    int mid = start + (end - start)/2;

    // left merge
    count += merge_sort(nums, start, mid);

    // right merge
    count += merge_sort(nums, mid + 1, end);

    // merge the 2 rows 
    count += merge(nums, start, mid, end);

    return count;
}

long long countMajoritySubarrays(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> prefix(n + 1, 0);

    for(int i = 0; i < n; i++){
        int val = nums[i] == target ? 1 : -1;
        prefix[i + 1] = prefix[i] + val;
    }

    long long ans = merge_sort(prefix, 0, prefix.size() - 1);
    return ans;
}

class Solution {
public:
    class Fenwick {
    public:
        vector<int> bit;
        int n;

        Fenwick(int n) {
            this->n = n;
            bit.assign(n + 1, 0);
        }

        void update(int index, int val) {
            while (index <= n) {
                bit[index] += val;
                index += index & -index;
            }
        }

        int query(int index) {
            int sum = 0;
            while (index > 0) {
                sum += bit[index];
                index -= index & -index;
            }
            return sum;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        // prefix sum range can be from -n to +n
        // so we shift by n + 2 to make all indexes positive
        int offset = n + 2;
        int size = 2 * n + 5;

        Fenwick ft(size);

        long long ans = 0;
        int prefix = 0;

        // Add prefix[0] = 0
        ft.update(prefix + offset, 1);

        for (int num : nums) {
            if (num == target) {
                prefix += 1;
            } else {
                prefix -= 1;
            }

            int index = prefix + offset;

            // Count previous prefix sums smaller than current prefix
            ans += ft.query(index - 1);

            // Add current prefix sum
            ft.update(index, 1);
        }

        return ans;
    }
};

int main() {

    vector<int> nums = {1,2,2,3};
    int target = 2;

    long long ans = countMajoritySubarrays(nums, target);
    cout<<"Number of Subarray is -> "<<ans<<endl;

    return 0;
}