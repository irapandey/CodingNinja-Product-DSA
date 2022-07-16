// Given a string S, count and return the number of substrings of S that are palindrome.
// Single length substrings are also palindromes. You just need to calculate the count, not the substrings.
// Input Format :
// String S
// Output Format :
// count of palindrome substrings
// Constraints :
// 1 <= Length of S <= 1000
// Sample Input :
// aba
// Sample Output :
// 4
// **Note : Here 4 corresponds to ("a","b","a","aba").

#include <iostream>
using namespace std;

int length(char s[]){
    int len = 0;
    for(int i =0; s[i] != '\0'; i++){
        len++;
    }
    return len;
}

int helper(char s[], int j , int k){
    int count = 0; 
    while(j >= 0 && k < length(s)){
        if(s[j] != s[k]){
            break;
        }
        count += 1;
        j --;
        k++;
    }
    return count;
}


int countPalindromeSubstrings(char s[]) {
    int count = length(s);
    for(int i = 0; i < length(s); i++){
        count += helper(s, i-1, i+1);
        count += helper(s, i, i+1);
    }
    return count;
}


int main() {
    char input[10000];
    cin >> input;
    cout << countPalindromeSubstrings(input) << endl;
}
