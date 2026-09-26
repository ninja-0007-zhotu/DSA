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
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        queue<TreeNode*> q;
        unordered_set<int> st;

        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            int need = k - node->val;

            // Have I already seen the required value?
            if (st.count(need))
                return true;

            st.insert(node->val);

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }

        return false;
    }
};