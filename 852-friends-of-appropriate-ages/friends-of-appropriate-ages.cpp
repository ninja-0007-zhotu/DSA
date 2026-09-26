class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n=ages.size();
        sort(ages.begin(),ages.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if (ages[i] <= 14) continue;
            int inx=upper_bound(ages.begin(),ages.end(),ages[i]/2 + 7)-ages.begin();
            int right=upper_bound(ages.begin(), ages.end(), ages[i]) - ages.begin();
            ans+=max(0,right-inx-1);
        }
        return ans;
    }
};