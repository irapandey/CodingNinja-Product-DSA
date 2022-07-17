// Sort an array A using Quick Sort.
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
// 1 5 2 7 3
// Sample Output 2 :
// 1 2 3 5 7 

#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

int part(int input[], int si, int ei){
    int pivot = input[ei];
    int i = si - 1;
    for(int j = si; j <= ei; j++){
        if(input[j]<pivot){
            i++;
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
        }
    }
    int temp = input[i+1];
    input[i+1] = input[ei];
    input[ei] = temp;
    return(i+1);
    
}

void qs(int input[], int si, int ei){
    if(si >= ei)
        return;
    int c = part(input, si, ei);
    qs(input, si, c-1);
    qs(input, c+1, ei);
}

void quickSort(int input[], int size) {
  
    qs(input, 0, size - 1);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}