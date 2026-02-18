class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int lo=1;
        int hi=n-2;

         // Edge cases
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n-1] != nums[n-2]) return nums[n-1];


        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];  
            }
            if(mid%2==0 && nums[mid]==nums[mid+1] or mid%2==1 && nums[mid]==nums[mid-1]){
                lo=mid+1; // elements is in left half;
            }

            else{ // or elements on the right half...
                hi=mid-1;
            }
        }
        return 1;
        
    }
};