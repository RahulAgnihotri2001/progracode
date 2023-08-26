//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        unordered_map<char,int> mp;
        int start=0;
        int end=0;
        int ans=-1;
        while(end<s.length()){
            if(mp.find(s[end])!=mp.end()){
                mp[s[end]]++;
                end++;
            }
            else{
                if(mp.size()<k){
                    mp[s[end]]++;
                }
                else{
                    while(mp.size()>=k){
                        mp[s[start]]--;
                        if(mp[s[start]]==0){
                            mp.erase(s[start]);
                        }
                        start++;
                    }
                     mp[s[end]]++;
                }
                end++;
            }
            if(mp.size()==k)
            ans=max(ans,end-start);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends