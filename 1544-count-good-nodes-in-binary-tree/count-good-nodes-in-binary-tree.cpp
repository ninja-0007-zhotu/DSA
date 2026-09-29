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
    int count=0;
public:
    void countGreatest(TreeNode* root, int max) {
         if(root==NULL) {
            return;
        }
        if(root->val>=max) {
            max=root->val;
            count++;
        }
        countGreatest(root->left, max);
        countGreatest(root->right, max);
    }

    public :
    int goodNodes(TreeNode* root) {
        countGreatest(root, root->val);
        return count;
    }
};