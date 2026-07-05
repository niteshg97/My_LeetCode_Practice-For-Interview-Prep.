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
class BSTIterator {
public:
    vector<int> v; // global variable to store the inorder elements.
    int index; // golbal varible so tht it can be accessed by all the functions 
    void InorderClass(TreeNode* root) {
        // inorderTraversal function to store all the inorder eements 
        if (root == NULL)
            return ;
        InorderClass(root->left);
        v.push_back(root->val);
        InorderClass(root->right);
    }
    BSTIterator(TreeNode* root) {
        // function to create the iterator
        InorderClass(root);
        index=0;
    }

    int next() {
        // function to return the next elements from the vector 
        return v[index++];
    }

    bool hasNext() {
        // function  to return true if next elements exixt else return false 
        return index< v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */