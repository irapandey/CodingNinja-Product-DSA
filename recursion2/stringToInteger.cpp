// Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
// Input format :
// Numeric string S (string, Eg. "1234")
// Output format :
// Corresponding integer N (int, Eg. 1234)
// Constraints :
// 0 <= |S| <= 9
// where |S| represents length of string S.
// Sample Input 1 :
// 00001231
// Sample Output 1 :
// 1231
// Sample Input 2 :
// 12567
// Sample Output 2 :
// 12567

#include <iostream>
#include<string>
#include<math.h>

using namespace std;

int stringToInt(string str, int output = 0) {
    // Write your code here
    if (str.length() == 1)
        return (str[0] - '0');
    
    double y = stringToInt(str.substr(1));
 
    double x = str[0] - '0';
 
    x = x * pow(10, str.length() - 1) + y;
    return int(x);
}

int stringToNumber(char input[], int output = 0) {
    // Write your code here
    string s = "";
    for(int i = 0; input[i] != NULL; i++){
        s += input[i];
    }
    return stringToInt(s);
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
