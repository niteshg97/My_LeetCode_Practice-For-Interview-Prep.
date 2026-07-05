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

// Note : inorder traversal is already arranged in in increasing order... 
// this is the best way to think 

class Solution {
public:
    vector<int> v;
    void InorderTraversal(TreeNode* root) {
        if(root == NULL)
            return;

        InorderTraversal(root->left);
        v.push_back(root->val);
        InorderTraversal(root->right);
    }

    bool findTarget(TreeNode* root, int k) {

        if(root == NULL)
            return false;

        // BST ko sorted vector me convert karo
        InorderTraversal(root);

        // Har pair check karo
        for(int i = 0; i < v.size(); i++) {

            for(int j = i + 1; j < v.size(); j++) {

                if(v[i] + v[j] == k)
                    return true;
            }
        }

        return false;
    }
};