#include <bits/stdc++.h>
using namespace std;
// in this problem, all the numbers are repeated 3 times except one number. We have to find that number

// Idea -> Add all the numbers in binary form bit-by-bit. If the sum at each bit is a multiple of 3N+1, then there exists the bit of a unique number. We'll take a mod by 3 of that sum bit to convert it in into  (in case of 3N) or 1 (in case of 3N+1).

// this function is adding the values of each number in binary form bit-by-bit
void updateSum(vector <int> &sumArray, int x) {
    // Extract all bits of x
    for(int i=0; i<32; i++) {
        int ith_bit = x & (1<<i); // this will check if bit at ith position is 0 or greater than 0
        if(ith_bit) // if ith_bit is greater than 0
            sumArray[i]++; // we'll increase the value at ith index of sumArray by 1
    }
}

// this function is converting a number from binary to decimal using sumArray
int numFromBits(vector <int> &sumArray) {
    int num = 0;
    for(int i=0; i<32; i++) 
        num += (sumArray[i] * (1<<i));

    return num;
}

int findUnique(vector <int> &v) {
    vector <int> sumArray(32, 0); // since it's a 32-bit number, we have declared an array of size 32 and making all of them 0

    for(int x: v)
        updateSum(sumArray, x);

    for(int i=0; i<32; i++)
        sumArray[i] %= 3;

    return numFromBits(sumArray);
}

int main(){
    int n;
    cin >> n;
    vector <int> v(n);

    for(int i=0; i<n; i++)
        cin >> v[i];

    cout << findUnique(v);
    return 0;
}