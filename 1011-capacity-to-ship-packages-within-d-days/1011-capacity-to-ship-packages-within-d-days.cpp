class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0); // sum of the weights ... le jayega 
        
        int ans = hi;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;  
            
            int daysNeeded = 1;
            int currentLoad = 0;
            
            for (int w : weights) {
                if (currentLoad + w > mid) {
                    daysNeeded++;
                    currentLoad = 0;
                }
                currentLoad += w;
            }
            
            if (daysNeeded <= days) {
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
