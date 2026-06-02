class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();
        if (n % groupSize != 0)
            return false;
        map<int, int> mp;

        for (int card : hand) {
            mp[card]++;
        }
        while (!mp.empty()) {

            int current = mp.begin()->first;

            for (int i = 0; i < groupSize; i++) {

                if (mp.find(current + i) == mp.end())
                    return false;

                mp[current + i]--;

                if (mp[current + i] == 0) {
                    mp.erase(current + i);
                }
            }
        }

        return true;
    }
};