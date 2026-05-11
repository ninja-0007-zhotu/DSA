class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<nums.size();i++)
        {
            int temp=nums[i];
            while(temp)
            {
                int x=temp%10;
                temp=temp/10;
                st.push(x);
            }
            while(!st.empty())
            {
                ans.push_back(st.top());
                st.pop();
            }

        }
        return ans;
    }
};