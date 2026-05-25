class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int maxLen = 0;
        int maxFreq = 0;
        vector<int> hash(26, 0);
        while (r < n) {
            hash[s[r] - 'A']++; // include current character
            maxFreq =max(maxFreq,hash[s[r] - 'A']); // maximum frequency character in window
            while ((r - l + 1) - maxFreq > k) { // invalid window
                hash[s[l] - 'A']--;
                l++;
            }
            // valid window length
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};