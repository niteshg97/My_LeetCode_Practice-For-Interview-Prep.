// mathod 2: optmized  solution 
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        int lo = 0;
        int hi = m - 1;

        while(lo <= hi){

            int mid = lo + (hi - lo) / 2;

            // find row index of maximum element in mid column
            int maxRow = 0;
            for(int i = 0; i < n; i++){
                if(mat[i][mid] > mat[maxRow][mid]){
                    maxRow = i;
                }
            }

            int left  = (mid > 0) ? mat[maxRow][mid-1] : -1;
            int right = (mid < m-1) ? mat[maxRow][mid+1] : -1;

            // peak found
            if(mat[maxRow][mid] > left && mat[maxRow][mid] > right){
                return {maxRow, mid};
            }

            // move left
            else if(left > mat[maxRow][mid]){
                hi = mid - 1;
            }

            // move right
            else{
                lo = mid + 1;
            }
        }

        return {-1,-1};
    }
};
