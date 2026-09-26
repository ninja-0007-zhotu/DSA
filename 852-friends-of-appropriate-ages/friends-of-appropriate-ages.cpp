class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> count(121, 0);
        for (int age : ages) count[age]++;
        
        vector<int> prefix(121, 0);
        for (int i = 1; i <= 120; i++) prefix[i] = prefix[i-1] + count[i];
        
        int res = 0;
        for (int age = 15; age <= 120; age++) { 
            if (count[age] == 0) continue;
            int minAge = age / 2 + 7;
            int total = prefix[age] - prefix[minAge];
            res += count[age] * (total - 1); 
        }
        return res;
    }
};