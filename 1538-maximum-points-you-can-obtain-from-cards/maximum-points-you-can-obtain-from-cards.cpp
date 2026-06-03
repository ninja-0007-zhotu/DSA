class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lSum=0;
        int rSum=0;
        int maxSum=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            lSum=lSum+cardPoints[i];
        }
        maxSum=lSum;
        int rightInd=n-1;
        for(int i=k-1;i>=0;i--){
            lSum=lSum-cardPoints[i];
            rSum=rSum+cardPoints[rightInd];
            rightInd=rightInd-1;
            maxSum=max(maxSum,lSum+rSum);
        }
        return maxSum;
    }
};