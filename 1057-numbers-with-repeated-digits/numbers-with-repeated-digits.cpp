class Solution {
public:
    string s;

    int dp[11][1024][2][2];

    int solve(int pos, int mask, int tight, int started) {

        if (pos == s.size()) {
            return started;
        }

        int &ans = dp[pos][mask][tight][started];

        if (ans != -1) return ans;

        ans = 0;

        int limit = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= limit; d++) {

            int newTight = tight && (d == limit);

            if (!started && d == 0) {
                ans += solve(pos + 1, mask, newTight, 0);
            }
            else {
                if (mask & (1 << d)) {
                    continue;
                }

                ans += solve(
                    pos + 1,
                    mask | (1 << d),
                    newTight,
                    1
                );
            }
        }

        return ans;
    }

    int numDupDigitsAtMostN(int n) {

        s = to_string(n);

        memset(dp, -1, sizeof(dp));

        int unique = solve(0, 0, 1, 0);

        return n - unique;
    }
};