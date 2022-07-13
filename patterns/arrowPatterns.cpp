// Print the following pattern for the given number of rows.
// Assume N is always odd.
// Note : There is space after every star.
// Pattern for N = 7
// *
//  * *
//    * * *
//      * * * *
//    * * *
//  * *
// *
// Input format :
// Integer N (Total no. of rows)
// Output format :
// Pattern in N lines
// Sample Input :
// 11
// Sample Output :
// *
//  * *
//    * * *
//      * * * *
//        * * * * *
//          * * * * * *
//        * * * * *
//      * * * *
//    * * *
//  * *
// *

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int upper = (n+1) /2;
    int lower = n / 2;

    for(int i = 1; i <= upper; i++){
        for(int k = 0; k < i - 1 ; k++){
            cout<<" ";
        }
        for(int k = 0; k < i; k++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    for(int i = 1; i <= lower; i++){
        for(int k = 1; k < lower-i; i++){
            cout<<" ";
        }
        for(int k = 0; k <= lower - i; k++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}