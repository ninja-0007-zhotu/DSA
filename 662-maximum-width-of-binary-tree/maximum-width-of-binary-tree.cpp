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
    void dfs(TreeNode* root , int depth , unsigned long long idx , unsigned long long& ans , vector<unsigned long long>& firstIdx){
        if(!root) return ;
        if(depth==firstIdx.size()){
            firstIdx.push_back(idx);
        }
        ans = max(ans, idx-firstIdx[depth] + 1);

        dfs(root->left , depth+1 , 2*idx+1 , ans , firstIdx);
        dfs(root->right , depth+1 , 2*idx+2 , ans , firstIdx);
    }
    int widthOfBinaryTree(TreeNode* root) {
        vector<unsigned long long>firstIdx ;
        unsigned long long ans = 0 ;
        dfs(root,0,0,ans,firstIdx);
        return ans ;
    }
};