#include<iostream>
#include<algorithm>
using namespace std;


int platformsNeeded(int arr[], int dep[], int n) {
    sort(arr, arr+n);
    sort(dep, dep+n);

    int pn = 1, res = 1;
    int i = 1, j = 0;

    while(i < n && j < n){
        if(arr[i] < dep[j]){
            pn++;
            i++;
            if(pn > res){
            res = pn;
        }
        }
        else{
            pn--;
            j++;
        }
        
    }
    return res;
}


int main()
{
	int n;
	cin>>n;
    int* arr=new int[n];
    int* dep=new int[n];
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
	for(int i=0;i<n;i++)
    {
    	cin>>dep[i];
	}
    cout<< platformsNeeded(arr, dep, n);
}
