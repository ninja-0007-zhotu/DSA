/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
            if(flag == 0) reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            flag = abs(flag - 1);
        }
        return ans;
    }
};