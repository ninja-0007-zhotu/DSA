class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDelete = arr[0];
        int oneDelete = 0;
        int answer = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            oneDelete = max(oneDelete + arr[i], noDelete);
            noDelete = max(arr[i], noDelete + arr[i]);

            answer = max({answer, noDelete, oneDelete});
        }

        return answer;
    }
};