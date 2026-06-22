class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n = nums.size();
        long int singlesum = 0;
        long int doublesum = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] <= 9) {
                singlesum += nums[i];
            } else {
                doublesum += nums[i];
            }
        }

        if (singlesum == doublesum)
            return false;
        else
            return true;
    }
};