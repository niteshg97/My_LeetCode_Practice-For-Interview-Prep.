class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        long long case1 =  nums[n-1] * nums[n-2] * nums[n-3];
        long long case2 =  nums[0] * nums[1] * nums[n-1];

        return max(case1, case2);
    }
};
