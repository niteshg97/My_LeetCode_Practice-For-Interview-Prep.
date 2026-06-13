class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        stack<int> openSt;
        stack<int> astriskSt;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                openSt.push(i);
            } else if (s[i] == '*') {
                astriskSt.push(i);
            } else {
                // first match with open if not present match with *
                if (!openSt.empty()) {
                    openSt.pop();
                } else if (!astriskSt.empty()) {
                    astriskSt.pop();
                } else {
                    return false;
                }
            }
        }
        // check if star appears before (
        while (!openSt.empty() && !astriskSt.empty()) {
            if (openSt.top() > astriskSt.top()) {
                return false;
            }
            openSt.pop();
            astriskSt.pop();
        }
        return openSt.empty();
    }
};

/// time complexity is o(n)
// space complexity is O(n)