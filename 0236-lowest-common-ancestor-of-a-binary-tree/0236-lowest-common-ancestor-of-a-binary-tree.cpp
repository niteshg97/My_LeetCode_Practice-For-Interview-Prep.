/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;

        if ((root == p) || (root == q))
            return root;

        TreeNode* leftN = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightN = lowestCommonAncestor(root->right, p, q);

        if ((leftN == NULL) && (rightN == NULL))
            return NULL;
        // case1; when both left and right exixt then the LCA is root
        if ((leftN != NULL) && (rightN != NULL)) {
            return root;
        }
        // case2; when one is NULL and the other is not NULL then the LCA is not
        // NULL val and vice versa.

        if (leftN == NULL && rightN != NULL) {
            return rightN;
        }

        return leftN;
    }
};