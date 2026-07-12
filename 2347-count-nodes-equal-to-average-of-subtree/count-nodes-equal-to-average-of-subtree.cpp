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
  int result =0;
  int sum(TreeNode* root,int &count){
    if(!root)
    return 0;
    count++;
    int l=sum(root->left,count);
    int r=sum(root->right,count);
    return l+r+root->val;

  }
  int solve(TreeNode* root){
    if(!root)
    return 0;
    int  count=0;
    int totalsum=sum(root,count);
    if(totalsum/count==root->val){ 
    result++;
    }
    solve(root->left);
    solve(root->right);
    return root->val;
  }
    int averageOfSubtree(TreeNode* root) {
        result=0;
        solve(root);
        return result;
    }
};