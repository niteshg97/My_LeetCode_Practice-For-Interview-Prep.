class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

void backtrack(vector<int>& candidates, int target, int start, int sum) {
    if (sum == target) {
    result.push_back(path);
    return;
    }
    if (sum > target) return;

    for (int i = start; i < candidates.size(); i++) {
    if (i > start && candidates[i] == candidates[i - 1])
    continue;

    path.push_back(candidates[i]);
    backtrack(candidates, target, i + 1, sum + candidates[i]);
    path.pop_back(); 
     }
}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0);
        return result;
    }
};