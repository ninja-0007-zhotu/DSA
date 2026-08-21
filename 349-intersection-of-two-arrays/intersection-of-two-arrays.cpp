class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int> ans;

        for(int x : nums1) {
            for(int y : nums2) {
                if(x == y)
                    ans.insert(x);
            }
        }

        return vector<int>(ans.begin(), ans.end());
    }
};