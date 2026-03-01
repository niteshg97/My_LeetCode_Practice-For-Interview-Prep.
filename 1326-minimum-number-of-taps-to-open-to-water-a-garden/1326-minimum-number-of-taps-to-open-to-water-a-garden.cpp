class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n + 1, n + 2);
        dp[0] = 0; // base case 

        for (int i = 0; i <= n; ++i) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            if (dp[start] != n + 2) {
                for (int j = start; j <= end; ++j) {
                    dp[j] = min(dp[j], dp[start] + 1);
                }
            }
        }

        // If dp[n] is still our "infinity" value, it's impossible
        return dp[n] == n + 2 ? -1 : dp[n];
    }
};