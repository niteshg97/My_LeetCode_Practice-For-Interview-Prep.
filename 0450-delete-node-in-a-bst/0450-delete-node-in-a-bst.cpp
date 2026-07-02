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

    TreeNode* deleteNode(TreeNode* root, int key) {
        // Tree empty hai
        if (root == NULL)
            return NULL;
        // Key chhoti hai -> left subtree me search karo
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        // Key badi hai -> right subtree me search karo
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        // Node mil gaya
        else {
            // Case 1:
            // Left child nahi hai
            if (root->left == NULL)
                return root->right;
            // Case 2:
            // Right child nahi hai
            if (root->right == NULL)
                return root->left;
            // Case 3:
            // Dono children exist karte hain
            // Right subtree ka sabse chhota node dhoondo
            TreeNode* successor = root->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }
            // Successor ki value current node me copy kar do
            root->val = successor->val;
            // Duplicate successor ko delete kar do
            root->right = deleteNode(root->right, successor->val);
        }
        return root;
    }
};