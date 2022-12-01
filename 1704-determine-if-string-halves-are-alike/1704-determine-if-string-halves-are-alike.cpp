class Solution {
public:
    bool halvesAreAlike(string s) {
        int check = 0;
    
        for (int i = 0; i < s.length(); i++) {
            s[i] = tolower(s[i]);
            
            if (i < s.size() / 2) {
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                    check++;
            }
    
            else {
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                    check--;
            }
        }
    
        return check == 0;
    }
};