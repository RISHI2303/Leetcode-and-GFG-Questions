* For even we can take any of the middle elements as median, no need to take their mean because for any number in the range of the 2 middle numbers the ans will be same. To understand it more clearly see explanation of approach 2.
​
**Note :** Steps for each number to reach another number is simple their absolute difference because in each step we can decrease or increase the value by 1.
​
**First Approach :**
In this approach we just find the median after sorting the array which is nums[n/2] and add the absolute difference of the elements in the array with the median.
​
Time Complexity : O(n logn) for sort + O(n) for loop = O(n logn), Space complexity : O(1)
​
```
class Solution {
public:
int minMoves2(vector<int>& nums) {
int n = nums.size(), steps = 0;
sort(nums.begin(), nums.end());
int median = nums[n/2]; // Finding median
for(int i=0; i<n; i++){
steps += abs(nums[i] - median); //Adding absolute difference
}
return steps;
}
};
```
​
**Second Approach :**
`If we notice carefully the median is always inside the range of nums[i] ans nums[n-1-i] elements.` Now for any value x in the range the total steps needed to reach x for both the numbers is `(x - nums[i]) + (nums[n-1-i] - x) = nums[n-1-i] - nums[i]`. So it is clear that the steps does'nt depend on the median. So if we just simply add the diffences of nums[i] ans nums[n-1-i] from i =0 to i =n/2 (Because after that elements will repeat) we will get the required answer.
​
For the same reason we didn't need the mean of the middle values in first approach in case of n is even.
​
So after sorting the array just add the differences of first and last element one by one i.e. nums[i] ans nums[n-1-i] from i =0 to i =n/2
​
Time Complexity : O(n logn) for sort + O(n/2) for loop = O(n logn), Space complexity : O(1)
​
class Solution {
public:
int minMoves2(vector<int>& nums) {
int n = nums.size(), steps = 0;
sort(nums.begin(), nums.end());
for(int i=0; i<n/2; i++){
steps += nums[n-1-i] - nums[i]; //Adding difference
}