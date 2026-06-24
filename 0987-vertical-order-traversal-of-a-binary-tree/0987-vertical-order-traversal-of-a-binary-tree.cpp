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

    map<int, vector<pair<int,int>>> columns;

    void dfs(TreeNode* node, int row, int col) {

        if (node == nullptr)
            return;

        columns[col].push_back({row, node->val});

        dfs(node->left, row + 1, col - 1);
        dfs(node->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        dfs(root, 0, 0);

        vector<vector<int>> result;

        for (auto &entry : columns) {

            auto &nodes = entry.second;

            sort(nodes.begin(), nodes.end());

            vector<int> column;

            for (auto &p : nodes) {
                column.push_back(p.second);
            }

            result.push_back(column);
        }

        return result;
    }
};