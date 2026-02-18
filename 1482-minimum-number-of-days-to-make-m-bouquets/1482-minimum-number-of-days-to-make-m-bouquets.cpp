class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        long long totalFlowersNeeded = 1LL * m * k;
        int n = bloomDay.size();
        
        if (totalFlowersNeeded > n) return -1;
        
        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());
        
        int ans = -1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            int bouquets = 0;
            int consecutive = 0;
            
            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= mid) {
                    consecutive++;
                    
                    if (consecutive == k) {
                        bouquets++;
                        consecutive = 0;
                    }
                } 
                else {
                    consecutive = 0;
                }
            }
            
            if (bouquets >= m) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};
