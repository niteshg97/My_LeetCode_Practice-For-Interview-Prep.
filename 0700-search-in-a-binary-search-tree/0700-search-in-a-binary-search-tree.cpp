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
    TreeNode* searchBST(TreeNode* root, int val) {

        // Tree empty hai
        if (root == NULL)
            return NULL;

        // Mil gaya
        if (root->val == val)
            return root;

        // Chhota hai to left me jao
        if (val < root->val)
            return searchBST(root->left, val);

        // Bada hai to right me jao
        return searchBST(root->right, val);
    }
};