#include <bits/stdc++.h>
using namespace std;

// Problem statement:
// Given an array arr of size n containing non-negative integers,
// the task is to divide it into two sets S1 and S2 such that the absolute
// difference between their sums is minimum and find the minimum difference

// Topics:
// DP, 0-1 Knapsack

// Time complexity: O(N2);
// space complexity: O(N2);

int minDifference(int arr[], int n)  { 
    
	    int sum=0;
	    
	    for(int i=0;i<n;i++) sum+=arr[i];
	    
	    int half = sum/2;
	    
	    vector<vector<int>> dp(n+1,vector<int>(half+1,0));

		// We are trying to find the subset whose sum is closest to the half sum of the whole array
	    
	    for(int i=1;i<n+1;i++){
	        for(int j=1;j<half+1;j++){

				// if current element in the array is smaller than or equal to the half sum, we have two choices,
				// either take or not take. we will go with the one which makes our sum maximum.
	            if(arr[i-1]<=j) dp[i][j] = max(dp[i-1][j],arr[i-1] + dp[i-1][j-arr[i-1]]);

				// if the element is greater than the half sum, we have no choice except not to take it.
	            else dp[i][j] = dp[i-1][j];
	        }
	    }

		// the final value stored in dp at index (n,half)
		// is the maximum sum of a subset smaller than or equal to half sum
		// this is one of the subset we need, other can be obtained by subtracting it by total sum
	    
		// final ans
	    return abs(sum-2*dp[n][half]);
	}

int32_t main() {

	
	int n=4;
	int arr[n] = {1,6,11,5};
	    
	cout<<minDifference(arr,n)<<endl;
	
	return 0;
}
