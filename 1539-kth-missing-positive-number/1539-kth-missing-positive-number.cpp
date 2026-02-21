// this solution using  binary search ..... time complexity is O(log(n))
// i have alreade solved this in o(n) , time complexity ..
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int lo=0;
        int hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int missingNo=arr[mid]-(mid+1);
            if(missingNo<k){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return k+hi+1;
    }
};