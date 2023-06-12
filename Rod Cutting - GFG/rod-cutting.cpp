//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
   int fun(int index,vector<int> &dp,int prices[]){
       if(dp[index]!=-1){
           return dp[index];
       }
       for(int i=1;i<=index/2;i++){
            dp[index]=max(dp[index],fun(index-i,dp,prices)+fun(i,dp,prices));
        }
        dp[index]=max(dp[index],prices[index-1]);
        return dp[index];
   }
  
    int cutRod(int price[], int n) {
        //code here
        // 1d dp 
        vector<int> dp(n+1,-1);
        dp[0]=0;
        return fun(n,dp,price);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends