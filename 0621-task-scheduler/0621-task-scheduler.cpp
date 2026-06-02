// method 1:- Using the Greedy approach ....
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> mp(26, 0);

        // Count frequencies
        for (char ch : tasks) {
            mp[ch - 'A']++;
        }

        sort(mp.begin(), mp.end());

        int maxFreq = mp[25];
        int gaps = maxFreq - 1;
        int idleSlots = gaps * n;

        // Fill idle slots with remaining tasks
        for (int i = 24; i >= 0; i--) {
            idleSlots -= min(mp[i], gaps);
        }

        if (idleSlots > 0) {
            return tasks.size() + idleSlots;
        }

        return tasks.size();
    }
};