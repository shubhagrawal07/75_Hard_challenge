#include <bits/stdc++.h>
using namespace std;

/* 
Problem statement:
Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]),
the task is to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Zeros in the grid indicates blanks, which are to be filled with some number between 1-9. You can not replace the element in the cell which is not blank.


*/


// Topics: backtracking, recursion

/* 
Time complexity: O(9pow(N2))
Space complexity: O(N2) 
*/

/*
Test case:
Input:
grid[][] = 
[[3 0 6 5 0 8 4 0 0],
[5 2 0 0 0 0 0 0 0],
[0 8 7 0 0 0 0 3 1 ],
[0 0 3 0 1 0 0 8 0],
[9 0 0 8 6 3 0 0 5],
[0 5 0 0 9 0 6 0 0],
[1 3 0 0 0 0 2 5 0],
[0 0 0 0 0 0 0 7 4],
[0 0 5 2 0 6 3 0 0]]
Output:
True
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9
*/

#define N 9

 bool valid(int i, int j, int grid[N][N],int val){
        for(int k=0;k<9;k++){
            // checking is val already exist in the curr row
            if(grid[i][k]==val) return false;
            
            // checking is val already exist in the curr col
            if(grid[k][j]==val) return false;
            
            // checking is val already exist in the curr 3*3 grid
            if(grid[3*(i/3)+k/3][3*(j/3)+k%3]==val) return false;
        }
        return true;
    }
    
    
    bool SolveSudoku(int grid[N][N])  
    { 
        //traverse through the grid
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                
                // checking if the current cell is empty or not
                if(grid[i][j]==0){
                    for(int val=1;val<=9;val++){
                        
                        //checking if we can put the curr val int the empty cell
                        if(valid(i,j,grid,val)){
                            grid[i][j]=val;
                            
                            // if filling val in empty cell leads to valid ans, return true
                            if(SolveSudoku(grid)) return true;
                            
                            // backtracking
                            else grid[i][j]=0;
                        }
                    }
                    
                    // if we cant put any element from 1 to 9 in the empty cell, we cant solve the sudoku
                    if(grid[i][j]==0)return false;
                }
            }
        }
        // if every cell is filled, return true
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }

int32_t main() {
    
    int grid[N][N]=
{{3,0,6,5,0,8,4,0,0},
 {5,2,0,0,0,0,0,0,0},
 {0,8,7,0,0,0,0,3,1},
 {0,0,3,0,1,0,0,8,0},
 {9,0,0,8,6,3,0,0,5},
 {0,5,0,0,9,0,6,0,0},
 {1,3,0,0,0,0,2,5,0},
 {0,0,0,0,0,0,0,7,4},
 {0,0,5,2,0,6,3,0,0}};

    SolveSudoku(grid);
    printGrid(grid);
	
	cout<<endl;
	
	return 0;
}
