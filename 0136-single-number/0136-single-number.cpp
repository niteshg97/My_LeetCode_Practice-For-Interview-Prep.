// m:2 using the Xor  Approach .. to Solve this problem T.C is O(N);
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            xorr=xorr^nums[i];
        }
        return xorr;
        
    }
};