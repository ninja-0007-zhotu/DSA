class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long ans = (n * (n-1))>>1;
        unordered_map<int, long long> m;
        for(int i =0; i <n ; ++i){
            int diff = i - nums[i];
            ans -= m[diff];
            ++m[diff];
        }
        return ans;
    }
};