class Solution {
public:
    int balancedStringSplit(string s) {
        if (s.length() == 0)
            return 0;
        int left = 0, right = 0, score = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == 'L')
                left++;
            else
                right++;
            if (left == right) 
                score++;
        }
        return score;
    }
};