class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        unordered_set<int> possible;

        for (int base : baseCosts)
            possible.insert(base);

        for (int t : toppingCosts) {
            unordered_set<int> next = possible;

            for (int cost : possible) {
                next.insert(cost + t);
                next.insert(cost + 2 * t);
            }

            possible = next;
        }

        int ans = *possible.begin();

        for (int cost : possible) {
            if (abs(cost - target) < abs(ans - target) ||
                (abs(cost - target) == abs(ans - target) && cost < ans)) {
                ans = cost;
            }
        }

        return ans;
    }
};