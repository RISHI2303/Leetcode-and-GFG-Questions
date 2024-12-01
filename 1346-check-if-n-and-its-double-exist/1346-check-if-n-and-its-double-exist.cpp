class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> map;

        for (int num : arr) {
            map[num]++;
        }

        for (int num : arr) {
            if (num != 0 && map.find(2 * num) != map.end()) {
                return true;
            }
            if (num == 0 && map[num] > 1) {
                return true;
            }
        }
        return false;
    }
};