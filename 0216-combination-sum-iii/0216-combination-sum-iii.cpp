class Solution {
private:
    void findCombinations(int ind, int k, int target,vector<int> &ds,vector<vector<int>> &ans) {
        if (ds.size() == k) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }
        for (int i = ind; i <= 9; i++) {
            if (i > target) break;

            ds.push_back(i);
            findCombinations(i + 1, k, target - i, ds, ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;

        findCombinations(1, k, n, ds, ans);

        return ans;
    }
};
