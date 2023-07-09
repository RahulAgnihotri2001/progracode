//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        int i=0;
        int j=0;
        stack<int> st;
        while(j!=B.size()){
            if(i<A.size() && A[i]==B[j]){
                i++;
                j++;
            }
            else  if(!st.empty() && st.top()==B[j]){
                st.pop();
                j++;
            }
            else{
                while(i<A.size() && A[i]!=B[j]){
                    st.push(A[i]);
                    i++;
                }
                if(i==A.size()){
                    return 0;
                }
                else{
                    i++;
                    j++;
                }
            }
        }
        if(i==A.size() && j!=B.size()){
            return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends