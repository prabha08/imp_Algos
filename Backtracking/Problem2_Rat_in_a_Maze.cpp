/* Rat In A Maze Problem
You are given a N*N maze with a rat placed at maze[0][0]. Find and print all paths that rat can follow to reach its destination i.e. maze[N-1][N-1]. Rat can move in any direc­tion ( left, right, up and down).
Value of every cell in the maze can either be 0 or 1. 
Cells with value 0 are blocked means rat can not enter into those cells and those with value 1 are open.

Input Format
Line 1 : Integer N
Next N Lines : Each line will contain ith row elements (separated by space)

Output Format :
One Line for every possible solution. 
Every line will have N*N maze elements printed row wise and are separated by space. 
Only cells that are part of solution path should be 1, rest all cells should be 0.
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 
Sample Output 1 Explanation :
Only 1 path is possible
Sample Input 2 :
3
1 0 1
1 1 1
1 1 1
Sample Output 2 :
1 0 0 1 1 1 1 1 1 
1 0 0 1 0 0 1 1 1 
1 0 0 1 1 0 0 1 1 
1 0 0 1 1 1 0 0 1 
Sample Output 2 Explanation :
4 paths are possible */

#include <bits/stdc++.h>
using namespace std;

int rowArr[4] = {-1, 1, 0,  0};
int colArr[4] = {0,  0, -1, 1};

int ans[20][20];

bool isValid(int maze[][20], int n, int row, int col) {
    if(row>=n || col>=n || row < 0 || col < 0) {
        return false;
    }
    if(maze[row][col] == 0) {
        return false;
    }
    if(ans[row][col] == 1) {
        return false;
    }
    return true;
}

void print(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<ans[i][j]<<" ";
        }    
    }
    cout<<endl;
}

void ratInAMaze(int maze[][20], int n, int row, int col) {
    //base case
    if(row>=n || col>=n || row < 0 || col < 0) {
        return;
    }
    if(row==n-1 && col==n-1) {
        print(n);
        return;
    }
   // print(n);
   // cout<<"row: "<<row<<" col: "<<col<<" ";
    for(int i=0; i<4; i++) {
        int new_row = row + rowArr[i];
        int new_col = col + colArr[i];
        if(isValid(maze, n, new_row, new_col)) {
            ans[new_row][new_col] = 1; 
       //     cout<<"new_row: "<<new_row<<" new_col: "<<new_col<<endl;;
            ratInAMaze(maze, n, new_row, new_col);
    		ans[new_row][new_col] = 0;
        }
    }
}

void ratInAMaze(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
    ans[0][0] = 1;
    ratInAMaze(maze, n, 0, 0);
}

/*
int main() {
    int maze[20][20];
    int n; cin>>n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>maze[i][j];
        }
    }
    ratInAMaze(maze, n);
}
*/
