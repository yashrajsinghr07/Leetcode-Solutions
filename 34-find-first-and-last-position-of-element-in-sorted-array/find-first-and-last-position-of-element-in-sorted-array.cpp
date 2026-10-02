class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last  = -1;

        int lo = 0;
        int hi = nums.size()-1;

        while(lo<=hi){
            int mid  = lo+(hi-lo)/2;
            if(nums[mid]== target){
                first  = mid;
                hi = mid-1;
            }
            else if(nums[mid]<target){
                lo = mid+1;
            }
            else{
                hi  = mid-1;
            }
        }
        lo = 0;
        hi = nums.size()-1;

        while(lo<=hi){
            int mid  = lo+(hi-lo)/2;
            if(nums[mid]==target){
                last = mid;
                lo=mid+1;

            }
            else if(nums[mid]<target){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }

        return {first,last};


        
    }
};