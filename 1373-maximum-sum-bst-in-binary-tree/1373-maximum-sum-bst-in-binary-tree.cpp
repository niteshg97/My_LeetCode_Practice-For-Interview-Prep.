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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */

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
    int ans = 0;
    struct Info{
        bool isBst;
        int sum;
        int mx;
        int mn;
    };

    Info find(TreeNode* root){
        if(root == NULL) return {1, 0, INT_MIN, INT_MAX};

        struct Info left = find(root->left);
        struct Info right = find(root->right);
        struct Info curr;
        if(left.mx < root-> val && right.mn > root->val && left.isBst && right.isBst){
            curr.isBst = 1;
            curr.sum = left.sum + right.sum + root->val;
            curr.mx = max(right.mx, root->val);
            curr.mn = min(left.mn, root->val);
            ans = max(ans, curr.sum);
        }
        else{
            curr.isBst = 0;
            curr.sum = max(left.sum, right.sum);
        }
        return curr;
    }
public:
    int maxSumBST(TreeNode* root) {
        find(root);
        return ans;
    }
};