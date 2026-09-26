class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> arr(n);
        vector<int> ans(n);
 
        for (int i = 0; i < n; i++) {
            arr[i] = intervals[i][0];
        }
 
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }
 
        sort(arr.begin(), arr.end());
 
        for (int i = 0; i < n; i++) {
            int val = binarySearch(arr, intervals[i][1]);

            if (val == -1)
                ans[i] = -1;
            else
                ans[i] = mp[arr[val]];
        }

        return ans;
    }

    int binarySearch(vector<int>& arr, int target) {
        int l = 0;
        int r = arr.size() - 1;

        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] == target) {
                return mid;
            }
            else if (arr[mid] > target) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};