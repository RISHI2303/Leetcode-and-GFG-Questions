class Solution {
public:
    int maxProfit(vector<int>& v) {
        if(is_sorted(v.rbegin(), v.rend())) // agr array decreasing order m sorted h to 0 return krenge
        return 0;

    int min_price = INT_MAX; // ye array m min element dekhega
    int max_profit = 0; // ye max profit dekhega array m

    for(int i=0; i<v.size(); i++) {
        if(v[i] < min_price) // ye condition min element find krne k liye starting se...
            min_price = v[i];

        else if(v[i]-min_price > max_profit) { // ye condition max profit find krne k liye 
                                               // agr abhi min element 1 h, to 3-1=2 and 6-1=5 but 5 > 2 -> max_profit = 5
            max_profit = v[i] - min_price;
        }
    }

    return max_profit;
        
    }
};