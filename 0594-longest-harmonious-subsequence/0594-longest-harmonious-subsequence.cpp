class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;

        for (int num : nums) {
            frequencyMap[num]++;
        }

        int maxLength = 0;

        for (auto& [num, count] : frequencyMap) {
            if (frequencyMap.count(num + 1)) {
                int currentLength = count + frequencyMap[num + 1];
                maxLength = max(maxLength, currentLength);
            }
        }

        return maxLength;
    }
};