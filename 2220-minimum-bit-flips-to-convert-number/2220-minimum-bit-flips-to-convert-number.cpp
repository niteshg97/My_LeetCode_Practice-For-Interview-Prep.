class Solution {
public:
    int minBitFlips(int start, int goal) {
        // take XOR of the both no and the count the total no of set bits ....
        int ans = start ^ goal ;
        cout<<ans;
        int count =0;
        while(ans>0){
        if(ans%2!=0){
            count++;
            }
            ans=ans/2;
        }
        return count ;
    }
};