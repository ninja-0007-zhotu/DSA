class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
             int rows = matrix.size();
        int cols = matrix[0].size();

        int ans = 0;

        for (int top = 0; top < rows; top++) {

            vector<int> colSum(cols, 0);

            for (int bottom = top; bottom < rows; bottom++) {

                for (int c = 0; c < cols; c++)
                    colSum[c] += matrix[bottom][c];

                unordered_map<int, int> freq;

                freq[0] = 1;

                int pref = 0;

                for (int x : colSum) {

                    pref += x;

                    if (freq.count(pref - target))
                        ans += freq[pref - target];

                    freq[pref]++;
                }
            }
        }

        return ans;
   
    }
};