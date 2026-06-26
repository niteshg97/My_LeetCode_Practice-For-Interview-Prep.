/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>>que;
        que.push({root,0});
        long long maxWidth = 0;
        while(!que.empty()){
            long long l = que.front().second;
            long long r = que.back().second;
            maxWidth=max(maxWidth,r-l+1);
            int n = que.size();
            while(n--){
                TreeNode* curr = que.front().first;
                long long idx = que.front().second;
                que.pop();
                if(curr->left){
                    que.push({curr->left,2*idx+1});
                }

                if(curr->right){
                    que.push({curr->right,2*idx+2});
                }

            }
        }
        return maxWidth;
        
    }
};