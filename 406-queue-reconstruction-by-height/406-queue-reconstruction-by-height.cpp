class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),[](vector<int> p1, vector<int> p2){
            return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
        });
        vector<vector<int>> sol;
        for (auto person : people){
            sol.insert(sol.begin() + person[1], person);
        }
        return sol;
    }
};