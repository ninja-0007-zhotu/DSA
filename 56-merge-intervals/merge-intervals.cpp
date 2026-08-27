class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>> ans;

        for (auto &in : a) {
            if (ans.empty() || ans.back()[1] < in[0])
                ans.push_back(in);
            else
                ans.back()[1] =
                    max(ans.back()[1], in[1]);
        }
        return ans;
    }
};
