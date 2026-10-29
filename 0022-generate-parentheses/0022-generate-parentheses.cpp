/// we are solving using the back tracking...
class Solution {
public:
    void solve(vector<string>& ans, string s, int open, int close, int n) {
        // base case
        if (close == n) {
            ans.push_back(s);
        }
        if (open < n) {
            solve(ans, s + '(', open + 1, close, n);
        }
        if (close < open) {
            solve(ans, s + ')', open, close + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, "", 0, 0 , n);
        return ans;
        }
};