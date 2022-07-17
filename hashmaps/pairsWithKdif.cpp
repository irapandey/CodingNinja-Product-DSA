// You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.
// Note: Take absolute difference between the elements of the array.
// Input Format:
// The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
// The following line contains n space separated integers, that denote the value of the elements of the array.
// The following line contains an integer, that denotes the value of K.
// Output format :
// The first and only line of output contains count of all such pairs which have an absolute difference of K. 
// Constraints :
// 0 <= n <= 10^4
// Time Limit: 1 sec
// Sample Input 1 :
// 4 
// 5 1 2 4
// 3
// Sample Output 1 :
// 2
// Sample Input 2 :
// 4
// 4 4 4 4 
// 0
// Sample Output 2 :
// 6

#include <iostream>
using namespace std;

#include<unordered_map>
#include<vector>
#include<algorithm>

int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
    // vector<int> unique;
    unordered_map<int, int> frequency;
    int res = 0;
    
    for(int i = 0; i < n; i++){
        frequency[arr[i]] += 1;
    	// vector<int>::iterator it = find(unique.begin(), unique.end(), arr[i]);
    	// if (it == unique.end()) {
    	// unique.push_back(arr[i]);
    	// }
    }
    if(k == 0){
        res = (n * (n-1)) / 2;
        return res;
    }
    
    
    for(int i = 0; i < n; i++){
        int ahead = arr[i] + k;
        int back = arr[i] - k;
        if(frequency[ahead] != 0){
            res += (frequency[arr[i]] * frequency[ahead]);
        }
        if(frequency[back] != 0){
            res += (frequency[arr[i]] * frequency[back]);
        }
        frequency[arr[i]] = 0;
    }
    return res;
    
}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}