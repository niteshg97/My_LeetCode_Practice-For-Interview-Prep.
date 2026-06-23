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

// Method ... generate all the path sum of the tree and then return the maxx
// path of the given sum...

class Solution {
public:
    int maxSum;
    int solve(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = solve(root->left);
        int right = solve(root->right);

        int neeche_hi_mil_gaya_answer = left + right + root->val; // (1)
        int koi_ek_accha = max(left, right) + root->val;          // (2)
        int only_root_accha = root->val;                          // (3)
        maxSum =max({maxSum,neeche_hi_mil_gaya_answer, koi_ek_accha, only_root_accha});
        return max(koi_ek_accha,only_root_accha);
    }
    int maxPathSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};