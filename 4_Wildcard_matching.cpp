#include <bits/stdc++.h>
using namespace std;

/* 
Problem statement:
Given two strings 'str' and a wildcard pattern 'pattern' of length N and M respectively,  You have to print '1' if the wildcard pattern is matched with str else print '0' .

The wildcard pattern can include the characters ‘?’ and ‘*’
‘?’ – matches any single character
‘*’ – Matches any sequence of characters (including the empty sequence)

Note: The matching should cover the entire str (not partial str).
*/


// Topics: DP, recursion, LCS

/* 
Time complexity: O(N*M)
Space complexity: O(N*M) 
*/

/*
Test case:
Input:
pattern = "ba*a?"
str = "baaabab"
Output: 1
*/

// declaring DP globally
vector<vector<int>>dp;
    
    int solve(string s1,string s2,int i,int j){
        
        // base condition
        if(i==0&&j==0) return dp[i][j]=1;
        
        // if any of the string become empty and other not, we return false
        if(i<0||j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        //if element match '?', we need to check the remaining string
        if(s1[i-1]==s2[j-1]||s1[i-1]=='?') dp[i][j] = solve(s1,s2,i-1,j-1);
        
        //if '*', we can either take the element into the '*' or ignore the '*'
        else if(s1[i-1]=='*') dp[i][j] = solve(s1,s2,i,j-1)||solve(s1,s2,i-1,j);
        
        //if element dont match, we simply return false
        else dp[i][j] = 0;
        
        return dp[i][j];
    }
    int wildCard(string pattern,string str)
    {
        
        int i=pattern.length(),j= str.length();
        
        //initializing and resizing DP
        dp.resize(i+1,vector<int>(j+1,-1));
        return dp[i][j] = solve(pattern,str,i,j);
        
    }

int32_t main() {
    
    string pattern = "ba*a?",str = "baaabab";
	cout<<wildCard(pattern,str)<<endl;
	
	return 0;
}
