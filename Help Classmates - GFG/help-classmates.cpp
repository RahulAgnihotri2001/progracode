//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // find earest smaller on right
        // to use stack
        stack<int> st;
        vector<int> answer;
        for(int i=arr.size()-1;i>=0;i--){
            if(st.empty()){
                answer.push_back(-1);
            }
            else if(st.top()>=arr[i]){
                while(!st.empty() && st.top()>=arr[i]){
                    st.pop();
                }
                 if(st.empty()){
                answer.push_back(-1);
                }
                else{
                    answer.push_back(st.top());
                }
            }
            else{
                answer.push_back(st.top());
            }
            st.push(arr[i]);
        }
        reverse(answer.begin(),answer.end());
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
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends