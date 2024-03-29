class Solution {
public:
    int distributeCandies(vector<int> &candyType) {
        unordered_set<int> st;
    
        for(int i: candyType)
            st.insert(i);
    
        return min(st.size(), candyType.size() / 2);
    }
};