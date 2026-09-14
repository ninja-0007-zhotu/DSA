class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        int n = nums.size();

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        deque<int> dq;

        int ans = n + 1;

        for (int i = 0; i <= n; i++) {

            // Remove candidates that already satisfy K
            while (!dq.empty() &&
                   pref[i] - pref[dq.front()] >= k) {

                ans = min(ans, i - dq.front());

                dq.pop_front();
            }

            // Maintain increasing prefix sums
            while (!dq.empty() &&
                   pref[i] <= pref[dq.back()]) {

                dq.pop_back();
            }

            dq.push_back(i);
        }

        return ans == n + 1 ? -1 : ans;
    }
};
