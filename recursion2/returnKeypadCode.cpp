// Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
// Return empty string for numbers 0 and 1.
// Note : 1. The order of strings are not important.
// 2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
// Input Format :
// Integer n
// Output Format :
// All possible strings in different lines
// Constraints :
// 1 <= n <= 10^6
// Sample Input:
// 23
// Sample Output:
// ad
// ae
// af
// bd
// be
// bf
// cd
// ce
// cf

#include <iostream>
#include <string>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    string keypad_ref[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    if(num == 0){
        output[0] = "";
        return 1;
    }
    
    int smallnum = num / 10;
    int smallOutput = keypad(smallnum, output);
    string key = keypad_ref[num%10];
    int n = key.size();
    string temp[smallOutput * n];
    int k = 0;
    
    for(int i = 0; i < smallOutput; i++){
        for(int j = 0; j < n; j++){
            temp[k] = output[i]  + key[j];
            k++;
        }
    }
    
    for(int i = 0; i<smallOutput*n; i++){
        output[i] = temp[i];
    }
    

    return n * smallOutput;
    
    
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
