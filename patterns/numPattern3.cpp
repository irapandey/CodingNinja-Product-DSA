// Print the following pattern
// Pattern for N = 4
// 4 4 4 4 4 4 4 
// 4 3 3 3 3 3 4 
// 4 3 2 2 2 3 4 
// 4 3 2 1 2 3 4 
// 4 3 2 2 2 3 4 
// 4 3 3 3 3 3 4 
// 4 4 4 4 4 4 4 
// Input Format :
// N (Total no. of rows)
// Output Format :
// Pattern in N lines
// Sample Input 1 :
// 5
// Sample Output 1 :
// 5 5 5 5 5 5 5 5 5 
// 5 4 4 4 4 4 4 4 5 
// 5 4 3 3 3 3 3 4 5 
// 5 4 3 2 2 2 3 4 5 
// 5 4 3 2 1 2 3 4 5 
// 5 4 3 2 2 2 3 4 5 
// 5 4 3 3 3 3 3 4 5 
// 5 4 4 4 4 4 4 4 5 
// 5 5 5 5 5 5 5 5 5 

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int upper = n;

    for(int i = 1; i <= upper; i++){
        for(int j = upper; j > upper - i; j--){
            cout<<j<<" ";
        }
        int spaces = 2 * (n - i) - 1;
        for(int j = 0; j < spaces; j++){
            cout<<(n-i+1)<<" ";
        }
        if(i!=n){
                for(int k = upper - i +1; k <= upper; k++){
                    cout<<k<<" ";
                }
            }
            else{
                for(int k = upper-i+2; k <= upper; k++){
                    cout<<k<<" ";
                }
            }
        cout<<endl;
    }
    int lower = n -1;
    for(int i = 1; i <= lower; i++){
        for(int j = n; j > i;j--){
            cout<<j<<" ";
        }
        int spaces = (2*i) - 1;
        for(int j = 0; j < spaces; j++){
            cout<<(i+1)<<" ";
        }
        for(int j = i+1; j <= n; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}