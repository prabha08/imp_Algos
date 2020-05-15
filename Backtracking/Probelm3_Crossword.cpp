/*
Crossword Problem
There is a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. 
Now, you are also provided with a word list that needs to placed accurately in the grid. 
Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'. 
Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  
Sample Test Cases:
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
*/
#include<bits/stdc++.h>
using namespace std;

string matrix[10], words[100];
int sz=0;

bool isSolved() {
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(matrix[i][j] == '-') {
                return false;
            }
        }
    }
    return true; 
}

void printMatrix() {
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
}

bool isValidHorizontal(int r, int c, string word) {
    int ctr=0;
    for(int i=c; i<10; i++) {
        if(matrix[r][i] == '-' || matrix[r][i] == word[i-c]) {
            ctr++;
        }
        else {
            break;
        }
    }
    if(ctr == word.length()) {
 //   cout<<" "<<ctr<<" "<<word.length()<<" ";
        return true;
    }
    return false;
}

bool isValidVertical(int r, int c, string word) {
    int ctr=0;
    for(int i=r; i<10; i++) {
        if(matrix[i][c] == '-' || matrix[i][c] == word[i-r]) {
            ctr++;
        }
        else {
            break;
        }
    }
    if(ctr == word.length()) {
        return true;
    }
    return false;
}

void fillHorizontal(int r, int c, int k, bool wordFilled[]) {
    string word = words[k];
    int size = word.length();
    
    for(int i=c; i<c+size; i++) {
        if(matrix[r][i] == '-') {
            matrix[r][i] = word[i-c];
            wordFilled[i-c] = true;
        } else if(matrix[r][i] == word[i-c]) {
            wordFilled[i-c] = false;
        } else {
            cout<<endl<<"there is an issue" <<endl;
        }
    }
}

void fillVertical(int r, int c, int k, bool wordFilled[]) {
    string word = words[k];
    int size = word.length();
    
    for(int i=r; i<r+size; i++) {
        if(matrix[i][c] == '-') {
            matrix[i][c] = word[i-r];
            wordFilled[i-r] = true;
        } else if(matrix[i][c] == word[i-r]) {
            wordFilled[i-r] = false;
        } else {
            cout<<endl<<"there is an issue" <<endl;
        }
    }
}

void resetHorizontal(int r, int c, int k, bool wordFilled[]) {
    string word = words[k];
    int size = word.length();
    for(int i=0; i< size; i++) {
        if(wordFilled[i]) {
            matrix[r][i+c] = '-';
        }
    }
}

void resetVertical(int r, int c, int k, bool wordFilled[]) {
    string word = words[k];
    int size = word.length();
    for(int i=0; i< size; i++) {
        if(wordFilled[i]) {
            matrix[i+r][c] = '-';
        }
    }
}

bool solveCrossWord(int k) {

    if(isSolved()) {
        printMatrix(); 
        return true;
    }
    if(k>=sz) {
        return false;
    }
//    for(int k=0; k<sz; k++) {
        for(int i=0; i<10; i++) {
            for(int j=0; j<10; j++) {
                if(isValidHorizontal(i, j, words[k])) {
                    //cout<<" "<<words[k]<< " is Hoz valid "<<i<<" "<<j<<endl;
                    bool wordFilled[words[k].size()];
                    fillHorizontal(i, j, k, wordFilled);
                //    cout<<endl;printMatrix(); cout<<endl;
                    if(solveCrossWord(k+1)) {
                        return true;
                    }
                    resetHorizontal(i, j, k, wordFilled);
                }
                if(isValidVertical(i, j, words[k])) {
                   //cout<<words[k]<< " is Ver valid "<<i<<" "<<j<<endl;
                    bool wordFilled[words[k].size()];
                    fillVertical(i, j, k, wordFilled);
               //     cout<<endl;printMatrix(); cout<<endl;
                    if(solveCrossWord(k+1)) {
                        return true;
                    }
                    resetVertical(i, j, k, wordFilled);
                }
            }
        }
//    }
    return false;
}

int main() {
    for(int i=0; i<10; i++) {
        cin>>matrix[i];
    }    
   int i=0;
   string my_str; cin>>my_str;

   stringstream s_stream(my_str); 
    my_str = my_str + ";";
   while(s_stream.good()) {
      string substr;
      getline(s_stream, substr, ';'); //get first string delimited by ;
      words[i++] = substr;
   }    
    sz = i;
    solveCrossWord(0);
}
