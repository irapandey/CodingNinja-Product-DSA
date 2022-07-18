#include<iostream>
using namespace std;

#include<vector>
#include<set>
bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
    vector<set<int>> rows(9), cols(9), blocks(9);
    
    for(int i = 0; i< 9; i++){
        for(int j = 0; j< 9; j++){
            if(board[i][j] == 0){
                continue;
            }
            else{
                int curr = board[i][j];
                if(rows[i].count(curr) || cols[j].count(curr) || blocks[((i/3) * 3) + (j/3)].count(curr)){
                    return false;
                }
                rows[i].insert(curr);
                cols[j].insert(curr);
                blocks[((i/3)*3) + (j/3)].insert(curr);
            }
        }
    }
	return true;

}

int main(){

  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
        }		
  }
  if(sudokuSolver(board)){
	cout << "true";	
  }else{
	cout << "false";	
  }
}


