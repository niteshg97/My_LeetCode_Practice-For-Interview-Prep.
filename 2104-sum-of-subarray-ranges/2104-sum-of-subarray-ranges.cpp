// brute force apprach 
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int largest = nums[i];
            int smallest = nums[i];
            // Start j from i to include single-element subarrays (though their range is 0)
            for (int j = i; j < n; j++) {
                largest = max(largest, nums[j]);
                smallest = min(smallest, nums[j]);
                sum += (largest - smallest);
            }
        }
        return sum;
    }
};
