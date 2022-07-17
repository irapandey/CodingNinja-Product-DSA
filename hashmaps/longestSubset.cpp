// Given an array, find and return the length of longest subarray containing equal number of 0s and 1s.
// Input Format :
// Line 1 : Integer N, size of array
// Line 2 : Array elements (separated by space)
// Output Format :
// Length of longest subarray
// Contraints :
// 1<= N <=10^6
// Sample Input 1 :
// 6 
// 1 0 0 1 1 1
// Sample Output 1 :
// 4    
// Sample Input 2 :
// 10 
// 1 1 1 0 0 0 1 1 0 0
// Sample Output 2 :
// 10

#include <cmath>
#include <iostream>
using namespace std;

#include<unordered_map>
using namespace std;

int max(int arr[], int n) {
	/* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    unordered_map<int, int> hM;
 
    int sum = 0; // Initialize sum of elements
    int max_len = 0; // Initialize result
    int ending_index = -1;
 
    for (int i = 0; i < n; i++)
        arr[i] = (arr[i] == 0) ? -1 : 1;
 
    // Traverse through the given array
 
    for (int i = 0; i < n; i++) {
        // Add current element to sum
 
        sum += arr[i];
 
        // To handle sum=0 at last index
 
        if (sum == 0) {
            max_len = i + 1;
            ending_index = i;
        }
 
        // If this sum is seen before, then update max_len
        // if required
 
        if (hM.find(sum) != hM.end()) {
            if (max_len < i - hM[sum]) {
                max_len = i - hM[sum];
                ending_index = i;
            }
        }
        else // Else put this sum in hash table
            hM[sum] = i;
    }
 
    for (int i = 0; i < n; i++)
        arr[i] = (arr[i] == -1) ? 0 : 1;
 
    
    return max_len;
}

int main() {
    	int n=0;
    	cin>>n;
    	int *arr = new int[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}
    	
    	cout << max(arr,n);
    	
	
}
