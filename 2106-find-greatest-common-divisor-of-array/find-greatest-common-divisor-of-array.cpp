class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = 1e9 , mx=0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]<mn) mn = nums[i];
            if(nums[i] > mx) mx = nums[i];
        }

        return gcd(mn,mx);
    }
};