class Solution {
public:
    void generate(vector<int>& a, int idx, int cnt, long long sum,
                  vector<vector<long long>>& v) {
        if (idx == a.size()) {
            v[cnt].push_back(sum);
            return;
        }

        generate(a, idx + 1, cnt, sum, v);
        generate(a, idx + 1, cnt + 1, sum + a[idx], v);
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        vector<vector<long long>> L(n + 1), R(n + 1);

        generate(left, 0, 0, 0, L);
        generate(right, 0, 0, 0, R);

        for (auto& x : R)
            sort(x.begin(), x.end());

        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = LLONG_MAX;

        for (int k = 0; k <= n; k++) {

            int need = n - k;

            for (long long x : L[k]) {

                long long target = total / 2 - x;

                auto it = lower_bound(R[need].begin(),
                                      R[need].end(),
                                      target);

                if (it != R[need].end()) {
                    long long sum = x + *it;
                    ans = min(ans, llabs(total - 2 * sum));
                }

                if (it != R[need].begin()) {
                    --it;
                    long long sum = x + *it;
                    ans = min(ans, llabs(total - 2 * sum));
                }
            }
        }

        return ans;
    }
};