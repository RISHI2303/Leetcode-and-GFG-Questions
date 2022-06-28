​
Note : We have to only deal with the frequencies not the characters. So position of the frequencies in the vector doesnt matter as we will never need which character's frequency are dealt with.
​
Now traverse the array from right to left as rightmost element is the greatest. We dont need to change the greatest element. So start traversing fron 24th position. (As 25th is the last element). Time taken = O(25) which is again constant so total time is O(N).
​
Now we will continue till frequencies become 0 for any element in the array as other elements left of it will also be 0. So break at the position where frequency is 0.
​
If the current frequency (freq[i]) is equal or greater than the previous one (freq[i+1) then we have to make the current frequency less than previous one but it should be also greater than or equal to 0. (Frequency can not be less than 0). So freq[i] = max(0, freq[i+1] -1).
​
In case of doubt : So here a question may arise that why so much headache as it is sorted freq[i] cannot be more than freq[i+1] just do ans++ ans reduce the frequncy by 1 i.e. freq[i]--. Yes in many cases it will work but think in case of more than 2 frequencies are equal then if we decrease a frequency then in next iteration the frequency will be more than the previous one ans if we only reduce 1 then the answer will not correct. So we make the frequency simply 1 less than previous and check the difference.
Example : If frequencies be [2,2,2,2] then if we just decrease the freq by 1 en each step then next step becomes [2,2,1,2], del = 1 -> [2,1,1,2], del = 2 -> [1,1,1,2], del = 3 which is not the desired result. Insted when difference is taken the result becomes [2,2,2,2] -> [2,2,1,2], del = 1 -> [2,0,1,2], del = 3 -> [0,0,1,2], del = 5 which is the desired ans.
​
But we also need the previous value of the frequency so that we can calculate the number of frequency decreased i.e. characters deleted. So we store the previous freq as prev before the step mentioned before.
​
So we add the reduced freq to the ans as del += prev - freq[i] (del is the answer).
​
Return del at the end which will contain the total number of frequency decreased i.e. total characters deleted.
​
**Example :**
​
Let the string be  : abbccdddeeffffggg
So count of a=1, b=2, c=2, d=3, e=2, f=4, g=3. So freq = {1,2,2,3,2,4,3,0,......,0}
So after sorting the elements of the freq array are = {0,......, 0, 1,2,2,2,3,3,4}
​
So at each step in the loop : [ Element of consideration is included in ' ', ans next element included in ( )]
​
```
[0, .... ,0,1,2,2,2,3,'3',(4)] -> '3' != 0, '3' < (4), So continue.
[0, .... ,0,1,2,2,2,'3',(3),4] -> '3' != 0, '3' == (3), So prev = '3', freq[i] = max(0, (3)-1) = 2, del += 3-2 i.e. del = 1
[0, .... ,0,1,2,2,'2',(2),3,4] -> '2' != 0, '2' == (2), So prev = '2', freq[i] = max(0, (2)-1) = 1, del += 2-1 i.e. del = 2
[0, .... ,0,1,2,'2',(1),2,3,4] -> '2' != 0, '2' > (1), So prev = '2', freq[i] = max(0, (1)-1) = 0, del += 2-0 i.e. del = 4
[0, .... ,0,1,'2',(0),1,2,3,4] -> '2' != 0, '2' > (0), So prev = '2', freq[i] = max(0, (0)-1) = 0, del += 2-0 i.e. del = 6
[0, .... ,0,'1',(0),0,1,2,3,4] -> '1' != 0, '1' > (0), So prev = '1', freq[i] = max(0, (0)-1) = 0, del += 1-0 i.e. del = 7
[0, .... ,'0',(0),0,0,1,2,3,4] -> '0' == 0, break;
```
​
**See all frequencies become distinct so return del i.e. 7