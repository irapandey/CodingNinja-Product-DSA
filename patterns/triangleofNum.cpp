// Print the following pattern for the given number of rows.
// Pattern for N = 4



// The dots represent spaces.



// Input format :
// Integer N (Total no. of rows)
// Output format :
// Pattern in N lines
// Constraints :
// 0 <= N <= 50
// Sample Input 1:
// 5
// Sample Output 1:
//            1
//          232
//        34543
//      4567654
//    567898765
// Sample Input 2:
// 4
// Sample Output 2:
//            1
//          232
//        34543
//      4567654


// Code Pair

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int k = 0; k < (n-i); k++){
            cout<<" ";
        }
        for(int j = 0; j < i; j++){
            cout<<(i+j);
        }
        int d = i -1;
        int start = 2*i - 2;
        for(int k = 0; k < d ; k++){
            cout<<start;
            start--;
        }
        cout<<endl;
    }
    

}