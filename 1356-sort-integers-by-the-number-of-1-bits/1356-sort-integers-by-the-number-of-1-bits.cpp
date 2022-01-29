class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](const int &a, const int &b){
            int countA = __builtin_popcount(a); // to find the number of set bits of a in binary form
            int countB = __builtin_popcount(b); // to find the number of set bits of b in binary form
            if(countA == countB) // if both the numbers have same no of set bits
                return (a < b); // if a < b (in decimal form), then return true and put a before b else vice versa
            else
                return (countA < countB); // if countA < countB, then return true and put a before b else vice versa
        });

        return arr; // since reference of this vector was passed as parameter, all the changes are done in the original vector only.
    }
};