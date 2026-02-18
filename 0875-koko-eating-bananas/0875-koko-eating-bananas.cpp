class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        
        int ans = hi;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            long long totalHour = 0;
            
            // calculate total hours for this speed
            for (int i = 0; i < piles.size(); i++) {
                totalHour +=ceil((double)piles[i] / mid);
  
            }
            
            if (totalHour <= h) {
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