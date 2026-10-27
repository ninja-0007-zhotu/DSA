
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push({freq[i], char('a' + i)});
            }
        }

        string ans;
        pair<int, char> prev = {0, '#'};

        while (!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();

            ans += ch;
            count--;

            if (prev.first > 0) {
                pq.push(prev);
            }

            prev = {count, ch};
        }

        return ans.size() == s.size() ? ans : "";
    }
};
