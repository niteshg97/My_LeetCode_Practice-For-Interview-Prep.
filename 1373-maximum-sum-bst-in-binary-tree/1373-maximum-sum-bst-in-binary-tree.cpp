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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */

class Solution {
public:

    // Final answer
    int maxSum = 0;

    // Har subtree ke baare me ye information return hogi
    struct NodeInfo {

        bool isBST;     // Kya subtree BST hai?

        int sum;        // Subtree ka sum

        int minValue;   // Minimum value

        int maxValue;   // Maximum value
    };

    NodeInfo solve(TreeNode* root) {

        // Empty tree is always BST
        if (root == NULL) {

            return {true, 0, INT_MAX, INT_MIN};
        }

        // Left subtree ki information
        NodeInfo left = solve(root->left);

        // Right subtree ki information
        NodeInfo right = solve(root->right);

        // Check karo current subtree BST hai ya nahi
        if (left.isBST &&
            right.isBST &&
            root->val > left.maxValue &&
            root->val < right.minValue) {

            int currentSum = left.sum + right.sum + root->val;

            // Answer update
            maxSum = max(maxSum, currentSum);

            return {

                true,

                currentSum,

                min(root->val, left.minValue),

                max(root->val, right.maxValue)

            };
        }

        // BST nahi hai
        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {

        solve(root);

        return maxSum;
    }
};