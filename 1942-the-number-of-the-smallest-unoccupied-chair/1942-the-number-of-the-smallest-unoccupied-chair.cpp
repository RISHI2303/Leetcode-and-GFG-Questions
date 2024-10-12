class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            leavingQueue;
        int targetArrival = times[targetFriend][0];

        sort(times.begin(), times.end());

        int nextChair = 0;
        set<int> availableChairs;

        for (auto time : times) {
            int arrival = time[0];
            int leave = time[1];

            while (!leavingQueue.empty() &&
                   leavingQueue.top().first <= arrival) {
                availableChairs.insert(leavingQueue.top().second);
                leavingQueue.pop();
            }

            int currentChair;
            if (!availableChairs.empty()) {
                currentChair = *availableChairs.begin();
                availableChairs.erase(availableChairs.begin());
            } else {
                currentChair = nextChair++;
            }

            leavingQueue.push({leave, currentChair});

            if (arrival == targetArrival) return currentChair;
        }

        return 0;
    }
};