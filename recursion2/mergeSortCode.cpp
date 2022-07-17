// Sort an array A using Merge Sort.
// Change in the input array itself. So no need to return or print anything.
// Input format :
// Line 1 : Integer n i.e. Array size
// Line 2 : Array elements (separated by space)
// Output format :
// Array elements in increasing order (separated by space)
// Constraints :
// 1 <= n <= 10^3
// Sample Input 1 :
// 6 
// 2 6 8 5 4 3
// Sample Output 1 :
// 2 3 4 5 6 8
// Sample Input 2 :
// 5
// 2 1 5 2 3
// Sample Output 2 :
// 1 2 2 3 5 

#include <iostream>
using namespace std;

void merge(int input[], int lower, int upper){
    int i, j, k; 
    int middle = (lower + upper) / 2;
    int left[middle-lower+1];
    int right[upper-middle];
    for (i = 0; i < middle-lower+1; i++)
    	left[i] = input[lower + i];
    for (j = 0; j < upper-middle; j++)
        right[j] = input[middle + 1 + j];
    i = 0; 
    j = 0; 
    k = lower; 
    for (k=lower;i < middle-lower+1 && j < upper-middle;k++) 
    {
        if (left[i] <= right[j]) 
            input[k] = left[i++];
        else 
            input[k] = right[j++];
    }
    while (i < middle-lower+1) 
        input[k++] = left[i++];
    while (j < upper-middle) 
        input[k++] = right[j++];
       
}

void merge_sort(int input[], int start, int end){
    if(start >= end)
        return;
    merge_sort(input, start, (start+end) / 2);
    merge_sort(input, ((start+end) / 2)+1, end);
    merge(input, start, end);
}

void mergeSort(int input[], int size){
	// Write your code here
      merge_sort(input, 0, size-1);  
    
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}