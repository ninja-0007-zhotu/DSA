class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n));

        dp[m-1][n-1] = max(1, 1 - dungeon[m-1][n-1]);

        for (int c = n-2; c >= 0; c--) {
            dp[m-1][c] = max(1, dp[m-1][c+1] - dungeon[m-1][c]);
        }

        for (int r = m-2; r >= 0; r--) {
            dp[r][n-1] = max(1, dp[r+1][n-1] - dungeon[r][n-1]);
        }

        for (int r = m-2; r >= 0; r--) {
            for (int c = n-2; c >= 0; c--) {
                int next = min(dp[r+1][c], dp[r][c+1]);

                dp[r][c] = max(1, next - dungeon[r][c]);
            }
        }

        return dp[0][0];
    }
};