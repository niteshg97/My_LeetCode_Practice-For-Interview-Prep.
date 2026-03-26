class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        using T = array<int,3>; // {val, row, col}
        priority_queue<T, vector<T>, greater<>> pq;
        int curMax = INT_MIN, start = 0, end = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            curMax = max(curMax, nums[i][0]);
        }
        
        while (true) {
            auto [val, r, c] = pq.top(); pq.pop();
            if (curMax - val < end - start) start = val, end = curMax;
            if (c + 1 == nums[r].size()) break;
            int nextVal = nums[r][c+1];
            pq.push({nextVal, r, c+1});
            curMax = max(curMax, nextVal);
        }
        return {start, end};
    }
};
