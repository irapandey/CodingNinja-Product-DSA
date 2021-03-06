// You are given with an array (of size N) consisting of positive and negative integers that contain numbers in random order.
// Write a program to return true if there exists a sub-array whose sum is zero else, return false.
// Input Format :
// Line 1 : An Integer N i.e. size of array 
// Line 2 : N integers, elements of the array (separated by space)
// Output Format :
// true or false
// Constraints :
// 1 <= N <= 10^5
// Sample Input 1 :
// 6 
// 7 1 3 -4 5 1
// Sample Output 1 :
// true
// Sample Input 2 :
// 5 
// -6 7 6 2 1
// Sample Output 2 :
// false

#include<iostream>
using namespace std;

#include<unordered_map>

bool subArrayZeroSum(int input[], int n) {
		
	/* Don't write main().
     	* the input array is already passed as function argument.
     	* Taking input and printing output is handled automatically. Return only true or false.
     	*/
    
    unordered_map<int, int> smap;
    smap[0] = 1;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += input[i];
        if(smap[sum] == 1){
            return true;
        }
        else{
            smap[sum] = 1;
        }
    }
            
	return false;
     	
}



int main()
{
    int n;
    int input[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    bool val = subArrayZeroSum(input, n);
    if(val)
    {
        cout<<"true";
    }
    else
    {
            cout<<"false";
    }
    return 0;
}

