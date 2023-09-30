#include <bits/stdc++.h>
using namespace std;

/*
Problem statement:
Given a string str, a partitioning of the string is a palindrome partitioning
if every sub-string of the partition is a palindrome.
Determine the fewest cuts needed for palindrome partitioning of the given string.

Topics: DP, recursion, MCM

Time complexity: O(N2)
Space complexity: O(N2)

Test case: "ababbbabbababa"
output: 3
eg: "a", "babbbab", "b", "ababa".
*/

// declaring DP globally
int dp[501][501];
    
    // helper fuction to check if string is palindrome or not
    int isPal(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }

    int solve(string str,int i,int j){
        //base case
        if(i>j) return 0;
        
        // if string is already a palindrome, no need to split , hence ans=0
        if(isPal(str,i,j)) return dp[i][j] = 0;
        
        // if we already calculated for this input, just use the previous ans
        if(dp[i][j]!=-1) return dp[i][j];
        
        
        int ans=INT_MAX;
        
        //taking a variable k and spliting the curr string in 2 string (i,k) and (k+1,j)
        for(int k=i;k<j;k++){
            
            // using recursion to solve for the two splited strings
            if(dp[i][k]==-1) dp[i][k]=solve(str,i,k);
            if(dp[k+1][j]==-1) dp[k+1][j] = solve(str,k+1,j);
            
            //storing the ans in the temp variable for the current slipt
            int temp = 1+dp[i][k]+dp[k+1][j];
            
            // checking if the current no. splits is smaller than the previos splits
            ans=min(ans,temp);
        }
        return dp[i][j] = ans;
    }

    int palindromicPartition(string str)
    {
        int n=str.length();
        
        // initializing the dp by -1
        memset(dp,-1,sizeof(dp));
        
        return solve(str,0,n-1);
    }

int32_t main() {

	string s = "ababbbabbababa";
	cout<<palindromicPartition(s)<<endl;
	
	return 0;
}
