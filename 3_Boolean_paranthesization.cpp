#include <bits/stdc++.h>
using namespace std;

/* 
Problem statement:
Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Note: The answer can be large, so return it with modulo 1003 
*/


// Topics: DP, recursion, MCM

/* 
Time complexity: O(N3)
Space complexity: O(N2) 
*/

/*
Test case: n = 7, s = "T|T&F^T"
output: 4
eg: ((T|T)&(F^T)), 
(T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
*/


// declaring DP globally
vector<vector<pair<int,int>>> dp;

// declaring mod globally
int mod=1003;


    
    pair<int,int> solve(string s,int i,int j){
        
        // if i>j, that means me have an empty string,
        // so no possible ways to get any true or false value
        if(i>j) return {0,0};
        
        // if i==j, means only one element. return 1 count of that element and 0 of other 
        if(i==j){
            if(s[i]=='T') return{1,0};
            else return {0,1};
        }
        
        // return stored value if already solved
        if(dp[i][j].first!=-1) return dp[i][j];

        
        int trueCount=0;
        int falseCount=0;
        
        
        // taking k such that s[k] is always an operator
        for(int k=i+1;k<j;k+=2){
            
            //splitting string in two, left side of k and right side of k
            // solving and storing for both sides
            if(dp[i][k-1].first==-1) dp[i][k-1] = solve(s,i,k-1);
            if(dp[k+1][j].first==-1) dp[k+1][j] = solve(s,k+1,j);
            
            int leftTrue = dp[i][k-1].first;
            int leftFalse = dp[i][k-1].second;
            int rightTrue = dp[k+1][j].first;
            int rightFalse = dp[k+1][j].second;
            
            
            // general boolean logic
            if(s[k]=='|'){
                trueCount += leftFalse*rightTrue + leftTrue*rightFalse + leftTrue*rightTrue;
                falseCount += leftFalse*rightFalse;
            }
            else if(s[k]=='&'){
                trueCount += leftTrue*rightTrue;
                falseCount += leftFalse*rightTrue + leftTrue*rightFalse + leftFalse*rightFalse;
            }
            else{
                trueCount += leftFalse*rightTrue + leftTrue*rightFalse;
                falseCount += leftTrue*rightTrue + leftFalse*rightFalse;
            }
            
            // taking modulo every repetition so the sum cannot overflow
            trueCount %= mod;
            falseCount %= mod;
        }
        
        return dp[i][j] = {trueCount,falseCount};
    }

    int countWays(int n, string s){
        
        // giving size and initializing the already declared DP
        dp.resize(n+1,vector<pair<int,int>>(n+1,{-1,-1}));
        return solve(s,0,n-1).first;
    }

int32_t main() {
    
    int n=7;
	string s = "T|T&F^T";
	cout<<countWays(n,s)<<endl;
	
	return 0;
}
