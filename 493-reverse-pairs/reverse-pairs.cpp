class Solution {
public:
    int mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;

        int cnt = mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);

        // Count reverse pairs
        int right = mid + 1;
        for (int left = low; left <= mid; left++) {
            while (right <= high &&
                   (long long)nums[left] > 2LL * nums[right]) {
                right++;
            }
            cnt += right - (mid + 1);
        }

        // Merge step
        vector<int> temp;
        int i = low, j = mid + 1;

        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= high) temp.push_back(nums[j++]);

        for (int k = low; k <= high; k++) {
            nums[k] = temp[k - low];
        }

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};