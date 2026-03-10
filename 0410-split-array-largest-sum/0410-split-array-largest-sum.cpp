class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k) return -1;
        
        int lo = *max_element(nums.begin(), nums.end());
        int hi = 0;
        
        for(int x : nums) hi += x;
        
        int ans = -1;
        
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            
            int students = 1;
            int pages = 0;
            
            for(int i = 0; i < n; i++){
                if(pages + nums[i] <= mid){
                    pages += nums[i];
                }
                else{
                    students++;
                    pages = nums[i];
                }
            }
            
            if(students <= k){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
        
    }
};