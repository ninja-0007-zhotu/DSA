class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int target = nums[i] + nums[j];

                int k = lower_bound(
                    nums.begin() + j + 1,
                    nums.end(),
                    target
                ) - nums.begin();

                count += k - j - 1;
            }
        }

        return count;
    }
};