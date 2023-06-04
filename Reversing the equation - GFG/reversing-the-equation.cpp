//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            reverse(s.begin(),s.end());
            int start=0;
            int end=0;
            while(end<s.length()){
                while(end<s.length() && isdigit(s[end])){
                    end++;
                }
                if(end!=s.length()){
                    reverse(s.begin()+start,s.begin()+end);
                    end++;
                    start=end;
                }
            }
            reverse(s.begin()+start,s.begin()+end);
            return s;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends