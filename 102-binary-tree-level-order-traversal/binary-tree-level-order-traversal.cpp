class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
      
        vector<vector<int>>res;
         if(root==NULL)return res;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<int>temp;
            int size=q.size();
            while(size--)
            {

                auto x= q.front();
                q.pop();
             
                temp.push_back(x->val);
             
                if(x->left){
                    q.push(x->left);
                }
                if(x->right){
                    q.push(x->right);
                }
            
            }   
            res.push_back(temp);

        }
       return res;
    }
};