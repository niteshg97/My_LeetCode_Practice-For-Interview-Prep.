class Solution {
public:
    int minBitFlips(int start, int goal) {
        // take XOR of the both no and the count the total no of set bits ....
        int ans = start ^ goal ;
        int count =0;
        for(int i=0;i<31;i++){
            if( ans & (1<<i)){
                count ++;
            }
        }
        return count;
    }
};