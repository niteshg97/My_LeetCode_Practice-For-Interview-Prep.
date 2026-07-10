class Solution {
public:
   void dfs(vector<vector<int>>& image, int i, int j, int newcolor , int orgcolor){
    int n = image.size();
    int m = image[0].size();
    // base case:
    if(i<0 || j<0 || i>=n || j>=m || image[i][j] == newcolor || image[i][j] !=orgcolor ){
        return;
    }
    image[i][j] = newcolor;
    dfs(image , i-1 , j , newcolor , orgcolor); // top 
    dfs(image , i , j+1, newcolor , orgcolor); // right 
    dfs(image , i+1 , j , newcolor , orgcolor); //bottom
    dfs(image , i , j-1 , newcolor , orgcolor); //left


   }
   
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        dfs(image , sr , sc ,color , image[sr][sc]);
        return image;

    }
};