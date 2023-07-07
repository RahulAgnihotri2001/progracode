//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        string answer="";
        int index=0;
        stack<char> st;
        while(index!=s.length()){
            if(isalpha(s[index]) || isdigit(s[index])){
                answer.push_back(s[index]);
            }
            else{
                if(s[index]=='(' || s[index]=='^'){
                    while(!st.empty() && st.top()=='^' && s[index]=='^'){
                        answer.push_back(st.top());
                        st.pop();
                    }
                    st.push(s[index]);
                }
                else if(s[index]=='*' || s[index]=='/'){
                    while(!st.empty() && (st.top()=='^' ||st.top()=='/' || st.top()=='*' )){
                        answer.push_back(st.top());
                        st.pop();
                    }
                    st.push(s[index]);
                }
                else if(s[index]==')'){
                    while(st.top()!='('){
                        answer.push_back(st.top());
                        st.pop();
                    }
                    st.pop();
                }
                else{
                    while(!st.empty() && (st.top()=='/' || st.top()=='*'|| st.top()=='^' || st.top()=='+' || st.top()=='-')){
                         answer.push_back(st.top());
                        st.pop();
                    }
                    st.push(s[index]);
                }
            }
            index++;
        }
        while(!st.empty()){
             answer.push_back(st.top());
                        st.pop();
        }
        return answer;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends