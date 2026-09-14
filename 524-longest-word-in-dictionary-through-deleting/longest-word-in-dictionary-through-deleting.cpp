class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {

        string ans = "";

        for (string word : dictionary) {

            int i = 0;
            int j = 0;

            while (i < s.size() && j < word.size()) {

                if (s[i] == word[j]) {
                    j++;
                }

                i++;
            }

            if (j == word.size()) {

                if (word.size() > ans.size() ||
                    (word.size() == ans.size() && word < ans)) {
                    ans = word;
                }
            }
        }

        return ans;
    }
};