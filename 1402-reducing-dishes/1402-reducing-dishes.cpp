class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(),greater<int>()); // sorted the array in decreasing order
        
        int total = 0, sum = 0;
        for (int i = 0; i < satisfaction.size(); i++) {
            if (sum + satisfaction[i] > 0) {
                sum += satisfaction[i];
                total += sum;
            } else {
                break;
            }
        }
        return total;
    }
};
