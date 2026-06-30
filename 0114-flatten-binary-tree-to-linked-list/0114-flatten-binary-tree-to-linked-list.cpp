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
    TreeNode* prev = NULL; // as global variable 

    void flatten(TreeNode* root) {

        // Base Case
        if (root == NULL)
            return;

        // Pehle right subtree flatten karo
        flatten(root->right);

        // Fir left subtree flatten karo
        flatten(root->left);

        // Current node ka right pointer
        // previous node se connect kar do
        root->right = prev;

        // Left pointer hamesha NULL hoga
        root->left = NULL;

        // Ab current node hi previous ban jayega
        prev = root;
    }
};