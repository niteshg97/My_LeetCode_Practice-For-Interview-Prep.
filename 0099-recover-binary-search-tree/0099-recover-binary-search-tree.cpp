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
    // Pehla galat node
    TreeNode* first = NULL;
    // Dusra galat node
    TreeNode* second = NULL;
    // Previous visited node (Inorder traversal ke liye)
    TreeNode* prev = NULL;
    void inorder(TreeNode* root) {
        if (root == NULL)
            return;
        // Left subtree
        inorder(root->left);
        // -----------------------------
        // Check BST property
        // -----------------------------
        if (prev != NULL && prev->val > root->val) {
            // Pehli baar violation mila
            if (first == NULL) {
                first = prev;
            }
            // Har violation me second update hota rahega
            second = root;
        }
        // Previous ko update karo
        prev = root;
        // Right subtree
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        // Dono wrong nodes ke values swap kar do
        swap(first->val, second->val);
    }
};