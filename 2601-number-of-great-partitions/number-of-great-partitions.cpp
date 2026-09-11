class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        
        long long total = 0;
        for (int x : nums)
            total += x;
        
        if (total < 2LL * k)
            return 0;
        
        int n = nums.size();
        
        vector<long long> dp(k, 0);
        dp[0] = 1;
        
        for (int x : nums) {
            for (int sum = k - 1; sum >= x; sum--) {
                dp[sum] = (dp[sum] + dp[sum - x]) % MOD;
            }
        }
        
        long long bad = 0;
        for (int sum = 0; sum < k; sum++) {
            bad = (bad + dp[sum]) % MOD;
        }
        
        long long totalWays = 1;
        for (int i = 0; i < n; i++) {
            totalWays = (totalWays * 2) % MOD;
        }
        
        return (totalWays - 2 * bad % MOD + MOD) % MOD;
    }
};