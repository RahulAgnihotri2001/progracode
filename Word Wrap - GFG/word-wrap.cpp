//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:

    int fun(vector<int> &nums, int k,int index,int pos,vector<vector<int>> &dp){
        if(index==nums.size()-1){
            return 0;
        }
        if(dp[index][pos]!=-1){
            return dp[index][pos];
        }
        int a=INT_MAX;
        int x=pos;
        pos=pos+nums[index];
        if(k-pos-1>=nums[index+1]){
            a=fun(nums,k,index+1,pos+1,dp);
        }
        int b=(k-pos)*(k-pos) + fun(nums,k,index+1,0,dp);
        dp[index][x]= min(a,b);
        return dp[index][x];
    }

    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        vector<vector<int>> dp(nums.size(),vector<int>(k,-1));
        return fun(nums,k,0,0,dp);
        
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends