#include <bits/stdc++.h>
using namespace std;

/* 
Problem statement:
Given two strings S1 and S2 of equal length, the task is to determine if S2 is a scrambled form of S1.

Scrambled string: Given string str, we can represent it as a binary tree by partitioning it into two non-empty substrings recursively.
Below is one possible representation of str = coder:
 
To scramble the string, we may choose any non-leaf node and swap its two children. 
Suppose, we choose the node co and swap its two children, it produces a scrambled string ocder.
Similarly, if we continue to swap the children of nodes der and er, it produces a scrambled string ocred.

Note: Scrambled string is not the same as an Anagram.

Print "Yes" if S2 is a scrambled form of S1 otherwise print "No".
*/


// Topics: DP, recursion, MCM

/* 
Time complexity: O(N2)
Space complexity: O(N2) 
*/

/*
Test case:
Input: S1="coder", S2="ocder"
Output: Yes
Explanation: ocder is a scrambled 
form of coder.

    ocder
   /    \
  oc    der
 / \    
o   c  

As "ocder" can represent it 
as a binary tree by partitioning 
it into two non-empty substrings.
We just have to swap 'o' and 'c' 
to get "coder".
*/

// declaring DP globally
unordered_map<string,bool> mp;
    
    bool isScramble(string s1, string s2){
        
        // base case
        if(s1==s2) return true;
        if(s1.length()!=s2.length()) return false;
        
        int n=s1.length();
        
        
        string dp = s1+'+'+s2;
        
        //checking if we already solved for the given strings
        if(mp.find(dp)!=mp.end()) return mp[dp];
        
        
        //taking a point i and splitting the string into (0,i) and (i,n)
        for(int i=1;i<n;i++){
            
            // checking for the case if the splitted string is not swapped. 
            // eg: oc_der(coder), here we can see that for i=2, string is not swapped
            if(isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i,n-i),s2.substr(i,n-i))) return mp[dp] = true;
            
            // checking for the case where string is slitted and swapped
            // eg: man_hu(human), here for i=2, string is splitted and swapped
            if(isScramble(s1.substr(0,i),s2.substr(n-i,i))&&isScramble(s1.substr(i,n-i),s2.substr(0,n-i))) return mp[dp] = true;
        }
        
        return mp[dp] = false;
    } 

int32_t main() {
    
    string s1 = "coder",s2 = "ocder";
	if(isScramble(s1,s2)) cout<<"Yes";
	else cout<<"No";
	
	cout<<endl;
	
	return 0;
}
