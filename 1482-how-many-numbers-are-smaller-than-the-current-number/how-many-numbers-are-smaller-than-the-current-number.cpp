
class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> result;
        for (auto i : nums)
        {
            int count = 0;
            for (auto j : nums)
            {
                if (i > j)
                    count++;
            }
            result.push_back(count);
        }
        return result;
    }
};