class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int freeDays = 0, latestEnd = 0;

        sort(meetings.begin(), meetings.end());

        for (auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            if (start > latestEnd + 1) {
                freeDays += start - latestEnd - 1;
            }

            latestEnd = max(latestEnd, end);
        }

        freeDays += days - latestEnd;

        return freeDays;
    }
};