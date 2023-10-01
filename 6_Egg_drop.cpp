#include <bits/stdc++.h>
using namespace std;

/* 
Problem statement:
You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped from a floor higher than f will break, and any egg dropped from or below floor f will not break.
There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.

Return the minimum number of moves that you need to determine with certainty what the value of f is.
*/


// Topics: DP, recursion, MCM

/* 
Time complexity: O(N*k2)
Space complexity: O(N*k) 
*/

/*
Test case:
Input:
N = 2, K = 10
Output: 4
*/

// declaring DP globally
vector<vector<int>> dp;
    
    int solve(int n,int k){
        
        //base cases
        if(k==1||k==0) return dp[n][k] = k;
        if(n==1) return dp[n][k]=k;
        
        
        //checking is already solved
        if(dp[n][k]!=-1) return dp[n][k];
        
        int ans = INT_MAX;
        
        for(int i=1;i<=k;i++){
            
            //no. of tries in the worst case scenario
            int temp = 1+ max(solve(n-1,i-1),solve(n,k-i));
            
            //saving the method with minimum tries
            ans=min(ans,temp);
        }
        return dp[n][k]=ans;
    }
    
    int eggDrop(int n, int k) 
    {
        //initializing and resizing the DP
        dp.resize(n+1,vector<int>(k+1,-1));
        return solve(n,k);
    }

int32_t main() {
    
    int n=2,k=10;
    cout<<eggDrop(n,k);
	
	cout<<endl;
	
	return 0;
}
