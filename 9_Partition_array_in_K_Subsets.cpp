#include <bits/stdc++.h>
using namespace std;

/* 
Problem statement:
Given an integer array a[ ] of N elements and an integer K, the task is to check if the array 
a[ ] could be divided into K non-empty subsets with equal sum of elements.
Note: All elements of this array should be part of exactly one partition.

*/


// Topics: backtracking, recursion

/* 
Time complexity: O(N*2pow(N))
Space complexity: O(2pow(N)) 
*/

/*
Test case:
N = 5
a[] = {2,1,4,5,6}
K = 3
Output: 
1
*/

bool solve(int curr,int sum,int k,int a[],bool flag[],int n){
    //  base cases
        if(k==0) return true;
        if(curr>sum) return false;

        // if a subset with required sum is found, look for other subsets.
        if(curr==sum) return solve(0,sum,k-1,a,flag,n);
        
        // looking for subsets
        for(int i=0;i<n;i++){

            // checking if element is already taken or not
            if(!flag[i]){

                // taking the element
                flag[i]=true;
                curr+=a[i];

                // if taking the element leads to a valid partitioning, return true
                if(solve(curr,sum,k,a,flag,n)) return true;

                // backtracking
                curr-=a[i];
                flag[i]=false;
            }
        }

        // if no valid partition is found, return false
        return false;
    }
  
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         int sum=0;
         for(int i=0;i<n;i++) sum+=a[i];
         
         // if sum is not a multiple of k, it cannot be devided into k subsets
         if(sum%k!=0) return false;
         
         sum=sum/k;
         bool flag[n]={false};
         
         return solve(0,sum,k,a,flag,n);
         
    }

int32_t main() {
    
   int n=5;
   int a[n]={2,1,4,5,6};
   int k=3;
	
	cout<<isKPartitionPossible(a,n,k);
	cout<<endl;
	
	return 0;
}
