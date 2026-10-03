// 
class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        // Finding pivot (smallest element)
        int pivot = -1;

        int lo = 0;
        int hi = n - 1;

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            // Case 1: mid itself is the smallest element
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                pivot = mid;
                break;
            }

            // Case 2: rotation point is after mid
            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }

        // If no rotation
        if (pivot == -1) {
            lo = 0;
            hi = n - 1;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                if (nums[mid] == target)
                    return mid;

                else if (nums[mid] > target)
                    hi = mid - 1;

                else
                    lo = mid + 1;
            }

            return -1;
        }

        // Search in left sorted part
        if (target >= nums[0] && target <= nums[pivot - 1]) {

            lo = 0;
            hi = pivot - 1;

            while (lo <= hi) {

                int mid = lo + (hi - lo) / 2;

                if (nums[mid] == target)
                    return mid;

                else if (nums[mid] > target)
                    hi = mid - 1;

                else
                    lo = mid + 1;
            }
        }

        // Search in right sorted part
        else {

            lo = pivot;
            hi = n - 1;

            while (lo <= hi) {

                int mid = lo + (hi - lo) / 2;

                if (nums[mid] == target)
                    return mid;

                else if (nums[mid] > target)
                    hi = mid - 1;

                else
                    lo = mid + 1;
            }
        }

        return -1;
    }
};