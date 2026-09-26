class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currentMax = nums[0];
        int maxSum = nums[0];

        int currentMin = nums[0];
        int minSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            // Normal Kadane → maximum subarray//
            currentMax = max(nums[i], currentMax + nums[i]);
            maxSum = max(maxSum, currentMax);

            // Reverse Kadane → minimum subarray//
            currentMin = min(nums[i], currentMin + nums[i]);
            minSum = min(minSum, currentMin);
        }

        return max(maxSum, -minSum);
    }
};