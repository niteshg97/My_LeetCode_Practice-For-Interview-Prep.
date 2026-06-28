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
// pre order ---> root->left->right
// in order  ---> left-->root-->right
// post order traversal: right -> root--> left
// these aare the traversal o traverse the ... pre order traversal

/*
Approach to solve this problem ..
first find root in preorder ;
then find the root index in inorder
and call a solve function (root->left, start , i-1);
and for right solve function(root->right, i+1 ,end )
*/

// method -1: TC=O(N^2)

class Solution {
public:
    // Inorder ke value -> index store karne ke liye
    unordered_map<int, int> mp;
    // idx preorder ka current root batayega
    TreeNode* solve(vector<int>& preorder, int start, int end, int& idx) {
        // Base Case
        if (start > end)
            return NULL;

        // Preorder ka current element root hai
        int rootVal = preorder[idx];
        idx++;
        // Root node bana do
        TreeNode* root = new TreeNode(rootVal);

        // O(1) me inorder index mil jayega
        int rootIndex = mp[rootVal];

        // Left subtree
        root->left = solve(preorder, start, rootIndex - 1, idx);

        // Right subtree
        root->right = solve(preorder, rootIndex + 1, end, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Inorder ke sabhi elements ka index store kar lo
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int idx = 0;

        return solve(preorder, 0, inorder.size() - 1, idx);
    }
};