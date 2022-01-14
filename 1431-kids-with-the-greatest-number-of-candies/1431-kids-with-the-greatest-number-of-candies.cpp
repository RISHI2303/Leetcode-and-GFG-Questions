class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maximumCandies = INT_MIN;
        vector <bool> v;

        for(auto i: candies) {
            maximumCandies = max(i, maximumCandies);
        }

        for(int i=0; i<candies.size(); i++) {
            if(candies[i]+extraCandies >= maximumCandies)
                v.push_back(true);
            else
                v.push_back(false);
        }

        return v;
    }
};