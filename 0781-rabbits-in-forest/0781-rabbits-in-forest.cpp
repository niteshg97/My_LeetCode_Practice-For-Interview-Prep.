class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        int result = 0;
        for (int ans : answers) {
            if (mp[ans] > 0) {
                mp[ans]--;
            } else {
                result += ans + 1;
                mp[ans] = ans; 
            }
        }
        return result;
    }
};
