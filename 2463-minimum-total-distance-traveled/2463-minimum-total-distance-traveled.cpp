class Solution {
public:
    long long minimumTotalDistance(vector<int>& robots,
                                   vector<vector<int>>& factories) {
        sort(begin(robots), end(robots));
        sort(begin(factories), end(factories));

        vector<int> factoryPositions;
        for (auto& factory : factories) {
            for (int i = 0; i < factory[1]; i++) {
                factoryPositions.push_back(factory[0]);
            }
        }

        int robotCount = robots.size(), factoryCount = factoryPositions.size();
        vector<long long> next(factoryCount + 1, 0),
            current(factoryCount + 1, 0);

        for (int i = robotCount - 1; i >= 0; i--) {
            if (i != robotCount - 1) next[factoryCount] = 1e12;
            current[factoryCount] = 1e12;

            for (int j = factoryCount - 1; j >= 0; j--) {
                long long assign =
                    abs(robots[i] - factoryPositions[j]) + next[j + 1];
                long long skip = current[j + 1];
                current[j] = min(assign, skip);
            }
            next = current;
        }
        return current[0];
    }
};