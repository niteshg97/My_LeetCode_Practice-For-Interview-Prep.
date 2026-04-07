class Solution {
private:
    void findCombinations(int ind,string &digits,vector<string> &mapping,string &ds,vector<string> &ans) {
        if (ind == digits.size()) {
            ans.push_back(ds);
            return;
        }
        string letters = mapping[digits[ind] - '0'];

        for (int i = 0; i < letters.size(); i++) {
            ds.push_back(letters[i]);
            findCombinations(ind + 1, digits, mapping, ds, ans);
            ds.pop_back(); // backtrack
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.empty()) return ans;

        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        string ds;
        findCombinations(0, digits, mapping, ds, ans);
        return ans;
    }
};
