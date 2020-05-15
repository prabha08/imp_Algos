/* N-Queen Problem
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess 
board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. 
You have to print all such configurations.

Input Format :
Line 1 : Integer N
Output Format :
One Line for every board configuration. 
Every line will have N*N board elements printed row wise and are separated by space
Note : Don't print anything if there isn't any valid configuration.
Constraints :
1<=N<=10
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 */

void print(int n, int arr[10][10]) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<arr[i][j]<<" ";
        }
    }
    cout<<endl;
}

bool possiblePos(int n, int arr[10][10], int row, int col) {
    //to check if there is queen in same col
    for(int i=0; i<row; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] == 1) {
                if(j==col) {
                    return false;
                }
            }
        }
    }
    
    //to check diagonal upper left
    for(int i=row, j=col; i>=0 && j>=0; j--,i--) {
        if(arr[i][j] == 1) 
            return false;
    }
    //to check diagonal upper right
    for(int i=row, j=col; i>=0 && j<=n-1; j++,i--) {
        if(arr[i][j] == 1) 
            return false;
    }
    return true;
}

void placeNQueens(int n, int arr[10][10], int row) {
    if(row>n-1) {
        print(n, arr);
        return;
    }
    for(int j=0; j<n; j++) {
        if(possiblePos(n, arr, row, j)) {
            arr[row][j] = 1;
            placeNQueens(n, arr, row+1);
            arr[row][j] = 0;
        }
    }
}

void placeNQueens(int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
int arr[10][10];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            arr[i][j] = 0;
        }
    }
    placeNQueens(n, arr, 0);    
}
