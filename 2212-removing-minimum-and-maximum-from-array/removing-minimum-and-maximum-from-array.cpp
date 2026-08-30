class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minELid = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxELid = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(minELid, maxELid);
        int right = max(minELid, maxELid);

        return min({
            right + 1,
            n - left,
            left + 1 + n - right
        });
    }
};