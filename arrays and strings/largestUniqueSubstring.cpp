// Given a string S, find the largest substring with no repetition i.e. largest substring which contain all unique characters.
// Input Format :
// String S
// Output Format :
// Largest unique substring
// Constraints :
// 1 <= Length os String S <= 10^3
// Sample Input:
// abcdabceb
// Sample Output:
// dabce

#include <iostream>
using namespace std;

int length(char input[]){
    int len = 0;
    for(int i =0; input[i] != '\0'; i++){
        len++;
    }
    return len;
}

void findLargestUniqueSubstring(char input[], char output[]){
        if(input[0] == '\0'){
            output[0] == '\0';
        }
        int last[256];
        for(int i = 0; i < 256; i++){
            last[i] = -1;
        }
        int currSubStart = 0;
        int maxSubStart = 0;
        int maxSubEnd = 0;
        int maxSubLen = 1;

        for(int i =0; input[i] != '\0'; i++){
            char curr = input[i];
            if(last[curr] >= currSubStart){
                if(i - currSubStart > maxSubLen){
                    maxSubStart = currSubStart;
                    maxSubEnd = i - 1;
                    maxSubLen = i - currSubStart;
                }
                currSubStart = last[curr] + 1;
            }
            last[curr] = i;
        }
        int len = length(input);

        if(len - currSubStart > maxSubLen){
            maxSubStart = currSubStart;
            maxSubEnd = len - 1;
            maxSubLen = len - currSubStart;
        }
        int j = 0;
        for(int k = maxSubStart; k <= maxSubEnd; k++){
            output[j++] = input[k];
        }
        output[j] = '\0';
        
}


int main() {
    char input[1000], output[1000];
    cin.getline(input, 1000);
    findLargestUniqueSubstring(input, output);
    cout << output << endl;
}
