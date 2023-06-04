//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> st;
        int index=0;
        while(index<x.length()){
            if(x[index]=='(' || x[index]=='[' || x[index]=='{'){
                st.push(x[index]);
            }
            else if(st.empty()){
                return false;
            }
            else if(x[index]==')' && st.top()=='('){
                st.pop();
            }
            else if(x[index]==']' && st.top()=='['){
                st.pop();
            }
            else if(x[index]=='}' && st.top()=='{'){
                st.pop();
            }
            else{
                return false;
            }
            index++;
        }
        if(st.empty()){
            return true;
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends