// Print the following pattern for the given number of rows.
// Pattern for N = 5
//  1    2   3    4   5
//  11   12  13   14  15
//  21   22  23   24  25
//  16   17  18   19  20
//  6    7    8   9   10
// Input format : N (Total no. of rows)

// Output format : Pattern in N lines

// Sample Input :
// 4
// Sample Output :
//  1  2  3  4
//  9 10 11 12
// 13 14 15 16
//  5  6  7  8
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<vector<int>> a;
        vector<int> temp;
        for(int x = 0; x < n; x++){
            temp.push_back(i+x);
        }
        a.push_back(temp);
    }
    int even = 0; 
    int odd = 1;

    for(int i = 0; i < a.size(); i++){
        if(i % 2 == 0){
            for(int j = 0; j < a[i].size(); j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    for(int i = a.size()-1; i>= 0; i--){
        if(i % 2 == 1){
            for(int j = 0; j < a[i].size(); j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}