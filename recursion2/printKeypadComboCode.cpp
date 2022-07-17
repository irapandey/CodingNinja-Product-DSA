// Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
// Note : The order of strings are not important. Just print different strings in new lines.
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

void printKeypad(int num, string output = ""){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string keypad_ref[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    if(num == 0){
        cout<<output<<endl;
        return;
    }
    int no = num % 10;
    string code = keypad_ref[no];
    int size = code.length();
    
    for(int i = 0; i < size;i++)
        printKeypad(num/10, code[i]+output);

}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
