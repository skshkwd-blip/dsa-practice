//BY RECURSION
#include <iostream>
#include <vector>
#include<string>
using namespace std;

class Solution{
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig){
        //horizontal
        for(int j=0; j<9; j++){
            if(board[row][j] == dig){
                return false;
            }
        }
        //vertical
        for(int i=0; i<9; i++){
            if(board[i][col] == dig){
                return false;
            }
        }
        //grid
        int sr = (row/3)*3 , sc = (col/3)*3;
        for(int i=sr; i<=sr+2;i++){//TC = O(9) => constant
            for(int j=sc; j<=sc+2; j++){
                if(board[i][j] == dig){
                    return false;
                }
            }
        }

        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col){
        if(row == 9){
            return true;
        }

        int nextRow = row, nextCol = col + 1;
        if(nextCol == 9){
            nextRow = row + 1;
            nextCol = 0;
        }

        if(board[row][col] != '.'){
            return helper(board,nextRow,nextCol);
        }

        for(char dig='1'; dig<='9'; dig++){
            if(isSafe(board,row,col,dig)){
                board[row][col] = dig;
                if (helper(board,nextRow,nextCol)){
                    return true;
                }
                board[row][col] = '.';//backtracking
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board){
        helper(board,0,0);
    }
};

int main() {
    vector<vector<char>> board = {
        {'5','3','4','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution s;
    s.solveSudoku(board);

    cout << "Solved Sudoku Board:\n";
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}