
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1,
                                       vector<int>& nums2, int k) {
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        int m = nums1.size(), n = nums2.size();
        if (m == 0 || n == 0 || k == 0) return {};

        for (int i = 0; i < min(m, k); i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        vector<vector<int>> ans;

        while (!pq.empty() && ans.size() < k) {
            auto [sum, i, j] = pq.top();
            pq.pop();

            ans.push_back({nums1[i], nums2[j]});

            if (j + 1 < n) {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return ans;
    }
};
