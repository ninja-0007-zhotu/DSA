class Solution {
public:
    int t[2001][2001];

    bool isAllStars(string &p, int i) {
        for (int k = 0; k < i; k++) {
            if (p[k] != '*')
                return false;
        }
        return true;
    }

    bool solve(int i, int j, string &p, string &s) {
        if (i == 0 && j == 0)
            return true;

        if (i == 0)
            return false;

        if (j == 0)
            return isAllStars(p, i);

        if (t[i][j] != -1)
            return t[i][j];

        if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
            return t[i][j] = solve(i - 1, j - 1, p, s);

        if (p[i - 1] == '*')
            return t[i][j] = solve(i - 1, j, p, s) ||
                              solve(i, j - 1, p, s);

        return t[i][j] = false;
    }

    bool isMatch(string s, string p) {
        memset(t, -1, sizeof(t));
        return solve(p.size(), s.size(), p, s);
    }
};