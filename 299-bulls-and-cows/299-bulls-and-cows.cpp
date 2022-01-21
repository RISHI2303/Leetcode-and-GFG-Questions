class Solution {
public:
    string getHint(string secret, string guess) {
        int i=0, bulls=0, cows=0, n=secret.length(), cnt=0;
        vector <int> buff(10, 0);
    
        while(secret[i] != '\0') {
            if(secret[i] == guess[i]){ // bulls case is direct
                bulls++;
            }
    
            // if number encountered is of secret, then increase it's value by 1
            // if number encountered is of guess, then decrease it's value by 1
            // it's obvious that if we reach a position where a buff index is < 0, then that number is present in guess.
            // and if buff index is > 0, then that number is present in secret.
            // in both the cases, cows are counted.
            else {
                if(buff[secret[i]-'0'] < 0)
                    cows++;
                if(buff[guess[i]-'0'] > 0)
                    cows++;
                buff[secret[i] - '0']++; // secret[i] - '0' is done to convert character to integer
                buff[guess[i] - '0']--;
            }
    
            i++;
        }
    
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};