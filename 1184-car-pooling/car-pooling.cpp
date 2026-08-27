class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> stamps(1001, 0);

        for (vector<int> vec : trips) {
            int people_count = vec[0];
            int start_time = vec[1];
            int end_time = vec[2];

            stamps[start_time] += people_count;
            stamps[end_time] -= people_count;
        }

        int total_curr_people = 0;

        for (int people_count : stamps) {
            total_curr_people += people_count;

            if (total_curr_people > capacity)
                return false;
        }
        return true;
    }
};