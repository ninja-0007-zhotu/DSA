class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        long long total = 0;

        for (int x : nums)
            total += x;

        int target = total % p;

        if (target == 0)
            return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        long long pref = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {

            pref += nums[i];

            int rem = pref % p;

            int need = (rem - target + p) % p;

            if (mp.count(need))
                ans = min(ans, i - mp[need]);

            mp[rem] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};