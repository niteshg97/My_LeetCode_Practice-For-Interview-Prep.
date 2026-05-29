class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);
        // store frequency of t
        for (char ch : t) {
            freq[ch]++;
        }
        int left = 0;
        int right = 0;
        int count = t.size();
        int minLen = INT_MAX;
        int start = 0;
        while (right < s.size()) {
            // if character is needed
            if (freq[s[right]] > 0) {
                count--;
            }
            freq[s[right]]--;
            // valid window found
            while (count == 0) {
                // update minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                // remove left character
                freq[s[left]]++;
                // if removed char becomes needed again
                if (freq[s[left]] > 0) {
                    count++;
                }
                left++;
            }
            right++;
        }
        if (minLen == INT_MAX) {
            return "";
        }
        return s.substr(start, minLen);
    }
};