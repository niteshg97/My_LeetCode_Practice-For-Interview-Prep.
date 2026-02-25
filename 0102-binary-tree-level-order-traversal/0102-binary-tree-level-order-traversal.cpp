class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            res.push_back({});
            for (int i = q.size(); i > 0; i--) {
                auto n = q.front(); q.pop();
                res.back().push_back(n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
        }
        return res;
    }
};
