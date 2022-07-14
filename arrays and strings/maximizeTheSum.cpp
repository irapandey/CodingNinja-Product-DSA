// Given 2 sorted arrays (in increasing order), find a path through the intersections that produces maximum sum and return the maximum sum.
// That is, we can switch from one array to another array only at common elements.
// If no intersection element is present, we need to take sum of all elements from the array with greater sum.
// Input Format :
//  Line 1 : An integer M i.e. size of first array
//  Line 2 : M integers which are elements of first array, separated by spaces
//  Line 3 : An integer N i.e. size of second array
//  Line 4 : N integers which are elements of second array, separated by spaces
// Output Format :
// Maximum sum value
// Constraints :
// 1 <= M, N <= 10^6
// Sample Input :
// 6
// 1 5 10 15 20 25
// 5
// 2 4 5 9 15
// Sample Output :
// 81
// Explanation :
// We start from array 2 and take sum till 5 (sum = 11). Then we'll switch to array at element 10 and take till 15. So sum = 36. Now, no elements left in array after 15, so we'll continue in array 1. Hence sum is 81

#include <iostream>
#include<algorithm>
using namespace std;

long maxPathSum(int a[], int b[], int n, int m)
{
    long res = 0, s1 = 0, s2 = 0, i = 0, j = 0;

    while(i < n && j < m){
        if(a[i] < b[j]){
            s1 += a[i];
            i++;
        }
        else if(b[j] < a[i]){
            s2 += b[j];
            j++;
        }
        else{
            res += a[i];
            res += max(s1,s2);
            s1 = 0;
            s2 = 0;
            i++;
            j++;
        }
    }
    while(i < n){
        s1 += a[i++];
    }
    while(j < m){
        s2 += b[j++];
    }
    res += max(s1,s2);
    
    return res;
    
}

int main() {
    int *a,*b,m,n,i;
    cin>>m;
    a=new int[m];
    for(i=0;i<m;i++)
        cin>>a[i];
    cin>>n;
    b=new int[n];
    for(i=0;i<n;i++)
        cin>>b[i];
    long ans = maxPathSum(a,b,m, n);
    cout << ans << endl;
    delete a;
    delete b;
    return 0;
}