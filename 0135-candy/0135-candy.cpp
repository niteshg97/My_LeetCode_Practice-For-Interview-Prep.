class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>L2R(n,1); // left to right candy initially sub ko 1 candy dena hain 
        vector<int>R2L(n,1); // right to left Candy 
        // left to right candy de rahe hain ... 
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                L2R[i]=max(L2R[i],L2R[i-1]+1);
            }
        }
       //  right to left candy distributing...;
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                R2L[i]=max(R2L[i],R2L[i+1]+1);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=ans+ max(L2R[i],R2L[i]);
        }
        return ans;
    }
};