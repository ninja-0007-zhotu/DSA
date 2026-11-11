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
void reverseinorder(TreeNode* root,TreeNode*& prev){
     if(root==NULL){
            return;
        }
        reverseinorder(root->right,prev);
        TreeNode* left=(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
        reverseinorder(left,prev);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* prev=NULL;
        reverseinorder(root,prev);
        return prev;
    }
};