// lets solve uisng map ... then we will optimized for log(n);
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> present(arr.begin(), arr.end());
        
        int current = 1;
        while (k > 0) {
            if (present.find(current) == present.end()) {
                k--;
                if (k == 0) return current;
            }
            current++;
        }
        return -1;
    }
};
