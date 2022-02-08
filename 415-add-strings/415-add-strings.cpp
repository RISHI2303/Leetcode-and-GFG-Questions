class Solution {
public:
    char numToChar(int n) {
        return n + '0'; // adding the ASCII value of 0 to make it a char
    }

    int charToNum(char c) {
        return c - '0'; // subtracting the ASCII value of 0 to make it an integer
    }

    string addStrings(string num1, string num2) {
        // reversing both strings b/c we store elements in the array in left to right fashion
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
    
        string result = "";

        // since we don't want to modify our algorithm, we'll check if num2 is necessarily of the longest length
        if(num1.length() > num2.length())
            swap(num1, num2);
    
        // since we are adding, we have to take care of the carry generated
        int carry = 0;
    
        // running the loop until shorter length since we want to find sum till that only
        for(int i=0; i<num1.length(); i++) {
            int d1 = charToNum(num1[i]);
            int d2 = charToNum(num2[i]);
            int sum = (d1 + d2 + carry); // we only want the last digit of this number in answer and rest is transfered to carry
            int od = sum % 10;
            carry = sum/10; // this will give us the remaining digits of the previous sum
            result.push_back(numToChar(od));
        }

        // now num1 is finished. If the carry from previous bit is generated, we have to take care of that too
        for(int i=num1.length(); i<num2.length(); i++) {
            int d = charToNum(num2[i]);
            int sum = (d + carry);
            int od = sum%10;
            carry = sum/10;
            result.push_back(numToChar(od));
        }
    
        if(carry)
            result.push_back('1'); // since maximum carry can be only 1 now
    
        reverse(result.begin(), result.end());
    
        return result;
    }
};