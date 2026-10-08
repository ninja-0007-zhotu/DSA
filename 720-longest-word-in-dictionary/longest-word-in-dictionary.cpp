class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());

        string ans = "";

        for (string word : words) {
            bool valid = true;
            
            for (int i = 1; i < word.size(); i++) {
                if (st.find(word.substr(0, i)) == st.end()) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                if (word.size() > ans.size() ||
                    (word.size() == ans.size() && word < ans)) {
                    ans = word;
                }
            }
        }

        return ans;
    }
};