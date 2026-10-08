class Solution {
    vector<vector<int>> ans;

public:
    void solve(int i, vector<int>& nums) {
        if (i == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }
        char st[21] = {'f'};
        for (int j = i; j < nums.size(); j++) {
            if (st[nums[j] + 10] == 't') {
                continue;
            }
            st[nums[j] + 10] = 't';
            swap(nums[i], nums[j]);
            solve(i + 1, nums);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};