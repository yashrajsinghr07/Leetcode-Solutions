class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        // 1. Find pivot
        int idx = -1;

        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        // If array is in descending order
        if(idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 2. Reverse elements after pivot
        reverse(nums.begin() + idx + 1, nums.end());

        // 3. Find just greater element than nums[idx]
        int j = -1;

        for(int i = idx + 1; i < n; i++) {
            if(nums[i] > nums[idx]) {
                j = i;
                break;
            }
        }

        // 4. Swap pivot and just greater element
        swap(nums[idx], nums[j]);
    }
};