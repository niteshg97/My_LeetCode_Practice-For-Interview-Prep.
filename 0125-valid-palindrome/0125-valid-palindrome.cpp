class Solution {
public:
    bool isPalindrome(string s) {
        return check(s, 0, s.length() - 1);
    }

    bool check(string &s, int l, int r) {
        // base case
        if (l >= r) return true;
        if (!isalnum(s[l])) return check(s, l + 1, r);
        if (!isalnum(s[r])) return check(s, l, r - 1);
        if (tolower(s[l]) != tolower(s[r]))
            return false;
        return check(s, l + 1, r - 1);
    }
};
