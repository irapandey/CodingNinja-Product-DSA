// Given an integer array A of size n. Find and print all the leaders present in the input array. An array element A[i] is called Leader, if all the elements following it (i.e. present at its right) are less than or equal to A[i].
// Print all the leader elements separated by space and in the same order they are present in the input array.
// Input Format :
// Line 1 : Integer n, size of array
// Line 2 : Array A elements (separated by space)
// Output Format :
//  leaders of array (separated by space)
// Constraints :
// 1 <= n <= 10^6
// Sample Input 1 :
// 6
// 3 12 34 2 0 -1
// Sample Output 1 :
// 34 2 0 -1
// Sample Input 2 :
// 5
// 13 17 5 4 6
// Sample Output 2 :
// 17 6

#include<iostream>
#include<climits>
#include<vector>
using namespace std;

void Leaders(int* arr,int len)
{
	/* Don't write main().
	 * Don't read input, it is passed as function argument.
	 * Print your output exactly in the same format as shown. 
	 * Don't print any extra line.
	*/
    vector<int> res;

    int mr = arr[len-1];
    res.push_back(mr);

    for(int i = (len-2); i >= 0; i--){
        if(mr <= arr[i]){
            res.push_back(arr[i]);
            mr = arr[i];
        }
    }
    for(int i = res.size() - 1; i >= 0; i--){
        cout<<res.at(i)<<" ";
    }

}

int main()
{
    int len;
    cin>>len;
	int *arr = new int[len + 1];
	
	for(int i=0;i<len;i++)
	{
		cin>>arr[i];
	}
	Leaders(arr,len);
}
