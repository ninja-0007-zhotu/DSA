class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int currMax = nums[0];
        int maxSum = nums[0];

        int currMin = nums[0];
        int minSum = nums[0];

        int total = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            // Normal Kadane
            currMax = max(nums[i], currMax + nums[i]);
            maxSum = max(maxSum, currMax);

            // Minimum Kadane
            currMin = min(nums[i], currMin + nums[i]);
            minSum = min(minSum, currMin);

            total += nums[i];
        }

        // All elements are negative
        if(maxSum < 0)
            return maxSum;

        // Normal vs circular
        return max(maxSum, total - minSum);
    }
};