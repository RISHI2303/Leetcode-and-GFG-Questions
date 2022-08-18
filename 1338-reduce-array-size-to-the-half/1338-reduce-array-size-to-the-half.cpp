class Solution {
    static const int MAX = 100000;
public:
    int minSetSize(vector<int>& arr) {        
        int freq[MAX+1]{}, freqBuckets[MAX+1]{}, ans = 0, maxFreq = 0;
        for(auto num : arr) maxFreq = max(maxFreq, ++freq[num]); // get frequency of elements
        for(int i = 0; i <= MAX; i++) freqBuckets[freq[i]]++;    // get instances of each frequency
        for(int i = maxFreq, deleteRequired = size(arr) / 2; deleteRequired > 0; i--) {
            if(!freqBuckets[i]) continue;                        // no elements having this frequency
            int noOfFreqToDelete = min(freqBuckets[i], deleteRequired / i + (deleteRequired % i > 0));  // above-mentioned optimization
            deleteRequired -= i * noOfFreqToDelete;              // delete elements having frequency = i
            ans += noOfFreqToDelete;                             // increment by number of instances of frequency (unique elements) deleted
        }   
        return ans;
    }
};