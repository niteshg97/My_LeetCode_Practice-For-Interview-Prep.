/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // ---------------- SERIALIZE ----------------
    string serialize(TreeNode* root) {

        // Agar tree empty hai
        if (root == NULL)
            return "";

        string ans = "";

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            // NULL node ko "#" se represent karenge
            if (node == NULL) {
                ans += "#,";
            }
            else {

                // Node ki value string me add karo
                ans += to_string(node->val) + ",";

                // Left aur Right child queue me daal do
                q.push(node->left);
                q.push(node->right);
            }
        }

        return ans;
    }

    // ---------------- DESERIALIZE ----------------
    TreeNode* deserialize(string data) {

        if (data.size() == 0)
            return NULL;

        stringstream ss(data);

        string str;

        // Sabse pehla token root hoga
        getline(ss, str, ',');

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            // ---------- LEFT CHILD ----------
            getline(ss, str, ',');

            if (str == "#") {
                node->left = NULL;
            }
            else {

                TreeNode* leftNode = new TreeNode(stoi(str));

                node->left = leftNode;

                q.push(leftNode);
            }

            // ---------- RIGHT CHILD ----------
            getline(ss, str, ',');

            if (str == "#") {
                node->right = NULL;
            }
            else {

                TreeNode* rightNode = new TreeNode(stoi(str));

                node->right = rightNode;

                q.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));