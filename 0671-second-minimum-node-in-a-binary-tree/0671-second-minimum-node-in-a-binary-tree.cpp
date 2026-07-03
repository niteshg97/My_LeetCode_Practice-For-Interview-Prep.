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
class Solution {
public:
    void solve(TreeNode* root, set<int>& ans) {
        if (root == NULL)
            return;
        solve(root->left, ans);
        ans.insert(root->val);
        solve(root->right, ans);
    }

    int findSecondMinimumValue(TreeNode* root) {
        set<int> ans;
        solve(root, ans);
        // i hae stired all the unique element in the set .. how to resturn the second minmum element form the set???
        if(ans.size()<2) return -1; // as told in question 

        auto it =  ans.begin();
        it++;
        return *it;
        
    }
};