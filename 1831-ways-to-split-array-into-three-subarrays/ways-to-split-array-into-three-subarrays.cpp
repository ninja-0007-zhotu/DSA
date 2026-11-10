class Solution {
public:
    int waysToSplit(vector<int>& nums) {

        int n = nums.size();
        const int MOD = 1e9 + 7;

        vector<long long> pref(n + 1, 0);

        for(int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        long long ans = 0;

        int j = 2, k = 2;

        for(int i = 1; i < n - 1; i++) {

            j = max(j, i + 1);

            while(j < n && pref[j] < 2 * pref[i])
                j++;

            k = max(k, j);

            while(k < n &&
                  2 * pref[k] <= pref[n] + pref[i])
                k++;

            if(j < k)
                ans = (ans + k - j) % MOD;
        }

        return ans;
    }
};