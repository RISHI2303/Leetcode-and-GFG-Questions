class Solution {
public:
    string interpret(string command) {
        int i=0;
        string s;

        while(command[i] != '\0') {
            if(command[i] == 'G') {
                s += 'G';
                i++;
            }

            else if(command[i] == '(' && command[i+1] == ')') {
                s += 'o';
                i += 2;
            }

            else {
                s += "al";
                i += 4;
            }
        }

        return s;     
    }
};