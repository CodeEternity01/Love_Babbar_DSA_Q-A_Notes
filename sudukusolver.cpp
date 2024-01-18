// sudoku solver problem
#include <iostream>;
#include <vector>
using namespace std;
bool issafe(int row,int col,vector<vector<int>> &board,int val){
    for(int i=0;i<9;i++){
        // row check
        if(board[row][i]==val)
           return false;
        // col check
        if(board[i][col]==val)
           return false;
        // 3*3 matrix check
        if(board[3*(row/3)+i/3][3*(col/3)+i/3]==val){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>> &board){
    int n=board[0].size();
    // n is 9 because in question be have a 9*9 matrix is given with some empty spots
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(board[row][col]==0){
                for(int val=1;val<=9;val++){
                    if(issafe(row,col,board,val)){
                        board[row][col]=val;
                        // recursive call
                        bool aagesolutionPossible=solve(board);
                        if(aagesolutionPossible)
                            return true;
                        else{
                            // backtrack
                            board[row][col]=0;
                        }  
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>> &sudoku){
    solve(sudoku);
}