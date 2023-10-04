#include <bits/stdc++.h>
using namespace std;

/* 
Problem statement:
Given a string s and a dictionary of words dict of length n,
add spaces in s to construct a sentence where each word is a valid dictionary word. 
Each dictionary word can be used more than once. Return all such possible sentences.

*/


// Topics: backtracking, recursion

/* 
Time complexity: O(n pow(2)*N))
Space complexity: O(N2) 
*/

/*
Test case:
Input: s = "catsanddog", n = 5 
dict = {"cats", "cat", "and", "sand", "dog"}
Output: (cats and dog)(cat sand dog)
*/

 // checking if the curr substring is valid word or not
    bool valid(string s,vector<string> dict,int n){
        for(int i=0;i<n;i++){
            if(dict[i]==s) return true;
        }
        return false;
    }
    
    void solve(string curr,string word,int i,int n,vector<string>dict,string s,vector<string> &ans){
        
        // base condition, string is fully traversed
        if(i==s.length()){
            
            // removing the extra space from back
            word.pop_back();
            ans.push_back(word);
        }
        
        for(int index=i;index<s.length();index++){
            
            curr.push_back(s[index]);
            
            // if the curr word is valid
            if(valid(curr,dict,n)){
                
                // add the curr word in the string
                word+=curr+" ";
                
                // check for the remaining string
                solve("",word,index+1,n,dict,s,ans);
                
                // backtracking
                word=word.substr(0,word.length()-curr.length()-1);
            }   
        }
        
        
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        string word="";
        vector<string> ans;
        solve("",word,0,n,dict,s,ans);
        return ans;
    }

int32_t main() {
    
   string s = "catsanddog";
   int n = 5;
    vector<string> dict = {"cats", "cat", "and", "sand", "dog"};
    
    vector<string> results = wordBreak(n,dict,s);
    
    for(auto a:results) cout<<a<<endl;
	cout<<endl;
	
	return 0;
}
