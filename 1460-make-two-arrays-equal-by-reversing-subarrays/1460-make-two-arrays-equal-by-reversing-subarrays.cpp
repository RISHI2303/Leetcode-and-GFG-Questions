class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> arrFreq;
        for (int num : arr) {
            arrFreq[num]++;
        }

        for (int num : target) {
            if (arrFreq.find(num) == arrFreq.end()) return false;

            arrFreq[num]--;
            if (arrFreq[num] == 0) {
                arrFreq.erase(num);
            }
        }
        return arrFreq.size() == 0;
    }
};