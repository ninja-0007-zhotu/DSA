class Solution {
public:
    vector<vector<int>> result;
    
    void powerset(vector<int> nums, int curr, vector<int> res, int n){
        if(curr == n){
            result.push_back(res);
            return;
        }
        powerset(nums, curr+1, res, n);
        res.push_back(nums[curr]);
        powerset(nums, curr+1, res, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        powerset(nums, 0, res, n);
        return result;
    }
};