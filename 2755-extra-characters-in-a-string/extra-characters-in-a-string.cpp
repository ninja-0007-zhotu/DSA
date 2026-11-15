class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        std::vector<int> dp(s.size(), INT_MAX);
        for (int i = 0; i < s.size(); ++i) {
            for (auto &word : dictionary) {
                if (word.size() > i + 1) {
                    continue;
                }
                int k = i - word.size() + 1;
                int j = 0;
                for (; j < word.size(); ++j) {
                    if (word[j] != s[k]) {
                        break;
                    }
                    ++k;
                }
                if (j == word.size()) {
                    int cand = i - (int)word.size() >= 0 ? dp[i - word.size()] : 0;
                    dp[i] = std::min(dp[i], cand);
                }
            }
            if (i > 0)
                dp[i] = std::min(dp[i], dp[i - 1] + 1);
            else
                dp[i] = std::min(dp[i], 1);

        }
        return dp[s.size() - 1];
        
    }
};