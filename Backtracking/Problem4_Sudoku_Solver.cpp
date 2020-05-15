/*
Sudoku Solver
Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), 
you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.
Input Format :
9 Lines where ith line contains ith row elements separated by space
Output Format :
 true or false
Sample Input :
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output :
true
*/

void findEmpty(int &r, int &c, int Board[][9]) {
    for(int i=0; i<9; i++) {
         for(int j=0; j<9; j++) {
            if(Board[i][j]==0) {
                r = i; c = j; return;
            }
        }   
    }
}

bool isComplete(int Board[][9]) {
        for(int i=0; i<9; i++) {
         for(int j=0; j<9; j++) {
            if(Board[i][j]==0) {
               return false;
            }
        }   
    }
    return true;
}

bool isValid(int r, int c, int no, int Board[][9]) {
    for(int i=0; i<9; i++) {
        if(Board[r][i] == no) return false;
    }
    for(int i=0; i<9; i++) {
        if(Board[i][c] == no) return false;
    }
    
    int rowFactor = (r/3) * 3;
    int colFactor = (c/3) * 3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(Board[rowFactor+i][colFactor+j] == no) return false;
        }
    }
    return true;
}

bool sudokuSolverHelper(int Board[][9]) {
    if(isComplete(Board)) {
        return true;
    }
    bool sol=false;
    int r, c;
    findEmpty(r, c, Board);
    for(int no=1; no<=9; no++) {
        if(isValid(r, c, no, Board)) {
            Board[r][c] = no;
            sol = sol || sudokuSolverHelper(Board);
            Board[r][c] = 0;
        }
    }
    return sol;
}

bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
    return sudokuSolverHelper(board);
}
