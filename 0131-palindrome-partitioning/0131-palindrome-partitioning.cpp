class Solution {
public:
    int n;
    bool isPalindrome(string &s, int l, int r) {
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void backtrack(string &s, int idx, vector<vector<string>> &res,vector<string> &curr) {
        if(idx == n ){
        res.push_back(curr);
            return;
        }
        for (int i = idx; i < n; i++) {
            if (isPalindrome(s, idx, i)) {
                curr.push_back(s.substr(idx, i - idx + 1));
                backtrack(s, i + 1, res, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<vector<string>> res;
        vector<string> curr;
        backtrack(s, 0, res, curr);
        return res;
    }
};