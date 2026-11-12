class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> arr(n, 0);
        for(int i =0; i < n ; ++i){
            int l = words[i].size() -1;
            if((words[i][0]=='a' or words[i][0]=='e' or
            words[i][0]=='i' or words[i][0]=='o' or
            words[i][0]=='u' ) and (words[i][l]=='a' or words[i][l]=='e' or
            words[i][l]=='i' or words[i][l]=='o' or
            words[i][l]=='u' )){
                arr[i] = 1;
            }
        }
            vector<int> psum(1+n, 0);
            for(int i = 0; i < n ; ++i){
                psum[i+1] = arr[i] + psum[i];
            }
            vector<int> ans(queries.size());
            for(int i =0; i< queries.size(); ++i){
                ans[i] = psum[queries[i][1]+1] - psum[queries[i][0]];
            }
            return ans;
    }
};