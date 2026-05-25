// using hashmap +prefixsum  concepts

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int sum = 0;
        int count = 0;
        mp[0] = 1;
        for (auto it : nums) {
            sum = sum + it;
            if (mp.find(sum - goal) != mp.end()) {//{ oldPrefixSum = currentSum - goal}
                count += mp[sum - goal]; 
            }
            mp[sum]++;
        }
        return count;
    }
};