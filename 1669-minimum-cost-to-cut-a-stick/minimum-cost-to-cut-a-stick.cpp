class Solution {
public:
    int rec(int low, int high, int mn, int mx, vector<int>&cuts,vector<vector<int>>&dp){
        if(low>high){
            return 0;
        }
        if(dp[low][high]!=-1) return dp[low][high];
        int ext=1e9;
        for(int i=low;i<=high;i++){
            ext=min(ext,rec(low,i-1,mn,cuts[i],cuts,dp)+rec(i+1,high,cuts[i],mx,cuts,dp)+mx-mn);
        }
        return dp[low][high]=ext;
    }
    int minCost(int n, vector<int>& cuts) {
        int m=cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>>dp(m+2,vector<int>(m+2));
        for(int i=m;i>=1;i--){
            for(int j=i;j<=m;j++){
                int chck=1e9;
                for(int k=i;k<=j;k++){
                    chck=min(chck,dp[i][k-1]+dp[k+1][j]+cuts[j+1]-cuts[i-1]);
                }
                dp[i][j]=chck;
            }
        }
        return dp[1][m];
    }
};