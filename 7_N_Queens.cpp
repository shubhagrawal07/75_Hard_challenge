#include <bits/stdc++.h>
using namespace std;

/* 
Problem statement:
The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
Given an integer n, find all distinct solutions to the n-queens puzzle. 
Each solution contains distinct board configurations of the n-queens’ placement, 
where the solutions are a permutation of [1,2,3..n] in increasing order, 
here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].

*/


// Topics: backtracking, recursion

/* 
Time complexity: O(N!)
Space complexity: O(N2) 
*/

/*
Test case:
Input:
N = 4
Output: [ 2 4 1 3 ]  [ 3 1 4 2 ] 
*/

void solve(int col,int n,vector<int> &leftRow,vector<int> &upperD,vector<int> &lowerD,vector<vector<int>> &ans,vector<int> &curr){
        // base condition, meaning all queens are placed
        if(col==n){
            ans.push_back(curr);
            return;
        }
        
        for(int row=0;row<n;row++){
            
            // checking if we can place the queen at position(row,col)
            if(leftRow[row]==0 && upperD[row+col]==0 && lowerD[(n-1)+(col-row)]==0){
                
                // updating the rows and diagonal we can't put any queens on after placing a queen at (row,col)
                leftRow[row]=1;
                upperD[row+col]=1;
                lowerD[(n-1)+(col-row)]=1;
                curr.push_back(row+1);
                
                // checking for next column
                solve(col+1,n,leftRow,upperD,lowerD,ans,curr);
                
                
                // backtracking
                leftRow[row]=0;
                upperD[row+col]=0;
                lowerD[(n-1)+(col-row)]=0;
                curr.pop_back();
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        
        vector<vector<int>> ans;
        vector<int> curr;
        
        // dimensions to validate the queens position
        vector<int> leftRow(n,0);
        vector<int> upperD(2*n-1,0);
        vector<int> lowerD(2*n-1,0);
        solve(0,n,leftRow,upperD,lowerD,ans,curr);
        return ans;
    }

int32_t main() {
    
    int n=4;
    vector<vector<int>> queenPositions = nQueen(n);
    
    for(auto a: queenPositions){
        cout<<" [ ";
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"] ";
    }
	
	cout<<endl;
	
	return 0;
}
