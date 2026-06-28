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
    // idx ko reference (&) se pass kar rahe hain taaki
    // preorder ka next root har recursive call me update ho.
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start,
                    int end, int& idx) {

        // Base Case:
        // Agar start end se bada ho gaya,
        // matlab is subtree me koi node nahi hai.
        if (start > end)
            return NULL;

        // Preorder ka current element hi root hoga.
        int rootVal = preorder[idx];

        // Agle recursive call ke liye idx badha do.
        idx++;

        // Root node bana do.
        TreeNode* root = new TreeNode(rootVal);

        // Inorder me root ki position dhoondo.
        int i;

        for (i = start; i <= end; i++) {
            if (inorder[i] == rootVal)
                break;
        }

        // Root ke left side wale elements
        // left subtree banayenge.
        root->left = solve(preorder, inorder, start, i - 1, idx);

        // Root ke right side wale elements
        // right subtree banayenge.
        root->right = solve(preorder, inorder, i + 1, end, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Preorder ka first element root hota hai.
        int idx = 0;

        return solve(preorder, inorder, 0, preorder.size() - 1, idx);
    }
};