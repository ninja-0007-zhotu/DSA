class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
           
        long long res = 0;
        vector<int> s;
        for (int a : nums) {
            res += lower_bound(s.begin(), s.end(), a) - s.begin();
            while (!s.empty() && s.back() > a)
                s.pop_back();
            s.push_back(a);
        }
        return res;
     
    }
};