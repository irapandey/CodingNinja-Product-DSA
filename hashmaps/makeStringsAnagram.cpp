// Given two strings S1 and S2, find and return the minimum number of deletions to be made (total count of deletions in both strings) in order to make the strings anagram.
// Anagram of a string is a string which is its permutation.
// For example "bbaa" and "abab" are anagrams of each other but "bbaa" and "aaab" are not.
// Input Format :
// Line 1 : String1
// Line 2 : String2
// Output Format :
// Number of deletions required
// Contraints :
// 1<= Length of string <=10^4
// Sample Input 1 :
// cde 
// abc
// Sample Output 1 :
// 4
// Sample Input 2 :
// aab
// aba
// Sample Output 2 :
// 0

#include <cmath>
#include <iostream>
using namespace std;

#include<cstring>
#include<unordered_map>


int makeAnagram(char str1[], char str2[]){
	
    int len = 0;
    unordered_map<char, int> m;
    int n1 = strlen(str1);
    int n2 = strlen(str2);

    for(int i = 0; i < n1; i++){
        if(m.find(str1[i]) != m.end()){
            m[str1[i]] = m[str1[i]] + 1;
        }
        else{
            m[str1[i]] = 1;
        }
    }
    for(int i = 0; i < n2; i++){
        if(m.find(str2[i]) != m.end() && m[str2[i]] != 0){
            len = len + 2;
            m[str2[i]] = m[str2[i]] - 1;
        }
    }

    int ans = n1 + n2 - len;
    return ans;
     
}

int main() {
    char str1[10010], str2[10010];
    cin>>str1;
    cin>>str2;
    
    cout << makeAnagram(str1,str2) << endl;
	
}
