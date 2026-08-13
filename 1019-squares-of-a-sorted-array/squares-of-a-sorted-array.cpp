class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;

        for(int x : nums) {
            result.push_back(x * x);
        }

        sort(result.begin(), result.end());

        return result;
    }
};