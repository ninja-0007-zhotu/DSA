 class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (char c : s1) {
            freq1[c - 'a']++;
        }

        int left = 0;

        for (int right = 0; right < m; right++) {
            freq2[s2[right] - 'a']++;

            // window size > s1 size
            if (right - left + 1 > n) {
                freq2[s2[left] - 'a']--;
                left++;
            }
 
            if (right - left + 1 == n) {
                if (freq1 == freq2)
                    return true;
            }
        }

        return false;
    }
};