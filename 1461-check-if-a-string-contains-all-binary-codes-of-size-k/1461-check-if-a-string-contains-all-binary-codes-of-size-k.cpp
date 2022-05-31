class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) 
            return false;
        
        unordered_set<string> st;
        
        for (int i = 0; i <= s.size()-k; i++) // inserting all substrings of length k in the set.
            st.insert(s.substr(i, k));
        
        // Ideally, the size of set should be equal to 2^k because if all the possible value of length k are resent, it would count upto 2^k.
        return st.size() == (1<<k);
    }
};