//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        // code here.
        if(S.length()==0){
            return S;
        }
        string answer="";
        answer.push_back(S[0]);
        for(int i=1;i<S.length();i++){
            if(answer.back()==S[i]){
                continue;
            }
            else{
                answer.push_back(S[i]);
            }
        }
        return answer;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends