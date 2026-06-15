class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n= intervals.size();
        vector<vector<int>>result;
        sort(intervals.begin(),intervals.end());
        result.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(intervals[i][0]<= result.back()[1]){ // overlap kar rahe hai toh merge kar do ans me ...
            result.back()[1] = max (result.back()[1] , intervals[i][1]);
            }
            else{
                result.push_back(intervals[i]); // if overlap nahi kar rahe hai toh direct result me daal do ... 
            }
        }
        return result;  
    }
};