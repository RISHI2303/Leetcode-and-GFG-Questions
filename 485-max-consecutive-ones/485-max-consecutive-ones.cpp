class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0, mCnt = 0;
        for(auto i: nums) {
            if(i == 1){
                mCnt = max(++cnt, mCnt);
            }
            else
                cnt = 0;
        }
    
        return mCnt;
    }
};