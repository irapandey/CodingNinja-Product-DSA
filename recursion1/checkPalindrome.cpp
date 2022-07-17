// Check whether a given String S is a palindrome using recursion. Return true or false.
// Input Format :
// String S
// Output Format :
// 'true' or 'false'
// Constraints :
// 0 <= |S| <= 1000
// where |S| represents length of string S.
// Sample Input 1 :
// racecar
// Sample Output 1:
// true
// Sample Input 2 :
// ninja
// Sample Output 2:
// false

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPalRec(char str[],
              int s, int e)
{   
    if (s == e)
    return true;
 
    if (str[s] != str[e])
    return false;
 
    if (s < e + 1)
    return isPalRec(str, s + 1, e - 1);
 
    return true;
}
bool checkPalindrome(char input[]) {
    // Write your code here
	int n = strlen(input);
     
    // An empty string is
    // considered as palindrome
    if (n == 0)
        return true;
     
    return isPalRec(input, 0, n - 1);
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
