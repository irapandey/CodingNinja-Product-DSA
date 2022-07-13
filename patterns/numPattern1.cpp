// Print the following pattern
// Pattern for N = 4


// The dots represent spaces.



// Input Format :
// N (Total no. of rows)
// Output Format :
// Pattern in N lines
// Sample Input :
// 5
// Sample Output :


// The dots represent spaces.

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
        
        cout<<endl;
    }
    

}
