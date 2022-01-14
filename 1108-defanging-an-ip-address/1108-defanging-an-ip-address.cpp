class Solution {
public:
    string defangIPaddr(string address) {
        string s = "";
        const string str = "[.]";
    
        for(auto ch: address) {
            if(ch == '.')
                s += str;
            else
                s += ch;
        }

        return s;
    }
};