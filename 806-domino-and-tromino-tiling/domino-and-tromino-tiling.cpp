class Solution {
public:
    const long long mod = 1e9 + 7;
    long long dp[1001][2];

    long long dominoes(int i, int n, bool possible) {
        if (i == n) return !possible;
        if (i > n) return 0;

        if (dp[i][possible] != -1)
            return dp[i][possible];

        if (possible) {
            return dp[i][possible] =
                (dominoes(i + 1, n, false) +
                 dominoes(i + 1, n, true)) % mod;
        }

        return dp[i][possible] =
            (dominoes(i + 1, n, false) +
             dominoes(i + 2, n, false) +
             2LL * dominoes(i + 2, n, true)) % mod;
    }

    int numTilings(int n) {
        memset(dp, -1, sizeof(dp));
        return dominoes(0, n, false);
    }
};