//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	
	    int fun(string &str,int i,int j ,vector<vector<int>> &dp){
	        if(i>= str.length() || j>=str.length()){
	            return 0;
	        }
	        if(dp[i][j]!=-1){
	            return dp[i][j];
	        }
	        int x=0;
	        int y=0;
	        if(str[i]==str[j] && i!=j ){
	            x=1+fun(str,i+1,j+1,dp);
	        }
	        y=max(fun(str,i+1,j,dp),fun(str,i,j+1,dp));
	        dp[i][j]=max(x,y);
	        return dp[i][j];
	        
	    }
	
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    // dp question
		    vector<vector<int>> dp(str.length(),vector<int>(str.length(),-1));
		    
		    return fun(str,0,0,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends