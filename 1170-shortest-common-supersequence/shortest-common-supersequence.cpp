class Solution {
public:
    int dp[1001][1001];

    int lcs(string &s1, string &s2, int n, int m) {
        if (n == 0 || m == 0)
            return 0;

        if (dp[n][m] != -1)
            return dp[n][m];

        if (s1[n - 1] == s2[m - 1]) {
            return dp[n][m] = 1 + lcs(s1, s2, n - 1, m - 1);
        }

        return dp[n][m] = max(
            lcs(s1, s2, n - 1, m),
            lcs(s1, s2, n, m - 1)
        );
    }

    string shortestCommonSupersequence(string str1, string str2) {
        memset(dp, -1, sizeof(dp));

        int n = str1.size();
        int m = str2.size();

        lcs(str1, str2, n, m);

        string ans = "";

        int i = n, j = m;

        while (i > 0 && j > 0) {

            if (str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--;
                j--;
            }
            else {
              
                lcs(str1, str2, i - 1, j);
                lcs(str1, str2, i, j - 1);

                if (dp[i - 1][j] > dp[i][j - 1]) {
                    ans += str1[i - 1];
                    i--;
                } else {
                    ans += str2[j - 1];
                    j--;
                }
            }
        }

        while (i > 0) {
            ans += str1[i - 1];
            i--;
        }

        while (j > 0) {
            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};