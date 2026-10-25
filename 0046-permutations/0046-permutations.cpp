// good question... ww can solve using the backtrackin..
// we can solve this uisng  backtracking u
class Solution {
public:
    vector<vector<int>> res;
    unordered_set<int>st;
    int n;

    void solve(vector<int>& temp, vector<int>& nums) {
        if (temp.size() == n) {
            res.push_back(temp);
            return; 
        }
        for (int i = 0; i < n; i++) {
            if(st.find(nums[i]) == st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(temp , nums);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        n = nums.size();
        solve(temp, nums);
        return res;
    }
};