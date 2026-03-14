// m-1 Brute force Approach ..we will optimixe latter 
// T.c O(4 n*m) ~ o(n*m) --> wrost case scenario..

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n =mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int up=(i>0) ? mat[i-1][j] : -1;
                int down=(i<n-1) ? mat[i+1][j] : -1;
                int left=(j>0) ? mat[i][j-1] :-1;
                int right=(j<m-1) ? mat[i][j+1] :-1;

                if(mat[i][j]>up && mat[i][j]>down && mat[i][j]>left && mat[i][j]>right){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
        
    }
};