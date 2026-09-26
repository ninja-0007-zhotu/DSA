class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {

        const long long MOD = 1e9 + 7;

        long long sum = 0;

        // LC 53 Kadane
        long long curr = 0;
        long long kadane = 0;

        // Maximum prefix
        long long prefix = 0;
        long long maxPrefix = 0;

        for (int x : arr) {

            sum += x;

            // LC 53
            curr = max(0LL, curr + x);
            kadane = max(kadane, curr);

            // Prefix
            prefix += x;
            maxPrefix = max(maxPrefix, prefix);
        }

        // LC 53 case
        if (k == 1)
            return kadane % MOD;

        // Maximum suffix
        long long suffix = 0;
        long long maxSuffix = 0;

        for (int i = arr.size() - 1; i >= 0; i--) {
            suffix += arr[i];
            maxSuffix = max(maxSuffix, suffix);
        }

        // Crosses one boundary
        long long ans = max(kadane,
                            maxPrefix + maxSuffix);

        // Crosses multiple copies
        if (sum > 0) {
            ans = max(ans,
                      maxPrefix +
                      maxSuffix +
                      (long long)(k - 2) * sum);
        }

        return ans % MOD;
    }
};