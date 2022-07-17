// Given two strings S (of length m) and T (of length n), you need to find and print out all the possible inter leavings that are possible of length (m + n).
// Inter leaving means - all possible combination of characters from both strings such that it contain all characters from both strings and, the respective ordering of characters of one string should remain same as in original.
// For eg.
// S = ab
// T = cd
// You need to find all strings of length 4 that contain all characters 'a', 'b', 'c' & 'd'. The only constraint on ordering of characters is - 'a' should always come before 'b' and 'c' should always come before 'd'.
// Note : Print all strings in different lines.
// Sample Input :
// abc
// def
// Sample Output :
// abcdef
// abdcef
// abdecf
// abdefc
// adbcef
// adbecf
// adbefc
// adebcf
// adebfc
// adefbc
// dabcef
// dabecf
// dabefc
// daebcf
// daebfc
// daefbc
// deabcf
// deabfc
// deafbc
// defabc

#include <iostream>
using namespace std;

#include<cstring>

void printIlsRecur (char *str1, char *str2, char *iStr, int m, int n, int i)
{
    
    if (m == 0 && n == 0)
        cout << iStr << endl ;
 
    
    if (m != 0)
    {
        iStr[i] = str1[0];
        printIlsRecur (str1 + 1, str2, iStr, m - 1, n, i + 1);
    }
 
    if (n != 0)
    {
        iStr[i] = str2[0];
        printIlsRecur(str1, str2 + 1, iStr, m, n - 1, i + 1);
    }
}
 
void printIls (char *str1, char *str2, int m, int n)
{
    char *iStr= new char[((m + n + 1)*sizeof(char))];
     
    iStr[m + n] = '\0';
     
    printIlsRecur (str1, str2, iStr, m, n, 0);
     
    free(iStr);
}
 
void interleaving(char* first, char* second) {
	// Write your code here
    printIls(first, second, strlen(first), strlen(second));

}

int main() {
    char *a = new char[1000];
    char *b = new char[1000];
    cin >> a;
    cin >> b;
    interleaving(a, b);
}
