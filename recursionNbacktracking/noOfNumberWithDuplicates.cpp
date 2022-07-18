#include <iostream>
#include<vector>
using namespace std;

long nums(long* input, int n, int * fact, int * freq){
    
    if(n == 0 || n == 1){
        return 0;
    }
    int d = 1;
     for(int i = 0; i<10; i++){
         if(freq[i] > 0){
             d *= fact[freq[i]];
         }
     }
    long ans = 0;
    
    for(long i = input[0] + 1 ; i < 10; i++){
        
        if(freq[i] > 0){
            
            ans +=  ((freq[i]*fact[n-1])/d);
            //ans +=  fact[n-1]/d * freq[i];
            
        }
    }
    
    freq[input[0]]--;
    ans += nums(input + 1, n-1, fact, freq);
    
    return ans;
}

long numberOfNumbersWithDuplicates(long num1){
	// Write your code here
    
    long temp = num1;
    vector<long> g1;
    while(temp > 0){
       
        g1.insert(g1.begin(), temp%10);
        temp = temp/10;
    }
    
    int n = g1.size();
    
    long * input = new long[n];
    int freq[10] = {};
    int * fact = new int[n+1];
    fact[0]=1;
    
    for(int i = 0; i < n; i++){
        input[i] = g1[i];
        fact[i+1] = (i+1) * fact[i];
        freq[input[i]]++;
        
    }
    
    
    return(nums(input, n, fact, freq));

	
}

int main() {
    long n;
    cin >> n;
    cout << numberOfNumbersWithDuplicates(n) << endl;
}
