
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % k != 0) return false;

        int target = sum / k;

        sort(nums.rbegin(), nums.rend());

        if (nums[0] > target) return false;

        int totalMasks = 1 << n;

        vector<int> dp(totalMasks, -1);
        dp[0] = 0;

        for (int mask = 0; mask < totalMasks; mask++) {
            if (dp[mask] == -1) continue;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) continue;

                if (dp[mask] + nums[i] > target)
                    continue;

                int nextMask = mask | (1 << i);

                dp[nextMask] =
                    (dp[mask] + nums[i]) % target;
            }
        }

        return dp[totalMasks - 1] == 0;
    }
};
