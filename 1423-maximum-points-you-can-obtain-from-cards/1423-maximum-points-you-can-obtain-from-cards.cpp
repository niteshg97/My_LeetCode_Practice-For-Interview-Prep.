// time complexity = O(2N) and the space complexity is  o(1):--> efficient solution 

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n =cardPoints.size();
        int leftSum=0;
        int rightSum=0;
        int maxSum=0;
        for(int i=0;i<k;i++){
            leftSum+=cardPoints[i];
            maxSum=leftSum+rightSum;
        }
        int lastIdx=n-1;
        for(int i=k-1;i>=0;i--){
            leftSum-=cardPoints[i];
            rightSum+=cardPoints[lastIdx];
            lastIdx=lastIdx-1;
            maxSum=max(maxSum,leftSum+rightSum);
        }
        return maxSum;
        
    }
};