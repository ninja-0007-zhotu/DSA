class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxi = 0;  

        for (int i = 0; i < n; i++) {
            for (int k = n - 1; k >= 0; k--) {
                int j = i + 1;

                while (j < k) {
                    maxi = max(maxi,
                               1LL * (nums[i] - nums[j]) * nums[k]);
                    j++;
                }
            }
        }

        return maxi;
    }
};