/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// in post order traversal :  left ---> right ----> root
class Solution {
public:
    void PostOrder(TreeNode* root, vector<int>& result) {
        if (root == NULL) {
            return;
        } else {
            PostOrder(root->left, result);
            PostOrder(root->right , result );
            result.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        PostOrder(root, result);
        return result;
    }
};