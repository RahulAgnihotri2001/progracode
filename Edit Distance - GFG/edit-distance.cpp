//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int dp(int i ,int j , string s , string t,vector<vector<int>> &vec){
        if(i==s.length() && j==t.length()){
            return 0;
        }
        if(i==s.length()){
            return t.length()-j;
        }
        if(j==t.length()){
            return s.length()-i;
        }
        if(vec[i][j]!=-1){
            return vec[i][j];
        }
        if(s[i]==t[j]){
            vec[i][j]= dp(i+1,j+1,s,t,vec);
        }
        else{
            // replace
            int x= dp(i+1,j+1,s,t,vec);
            int y= dp(i+1,j,s,t,vec);
            int z=dp(i,j+1,s,t,vec);
            vec[i][j]=1+min(x,min(y,z));
        }
        return vec[i][j];
    }  
  
    int editDistance(string s, string t) {
        // Code here
        //DP Question 
        vector<vector<int>> vec(s.length(),vector<int>(t.length(),-1));
        return dp(0,0,s,t,vec);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends