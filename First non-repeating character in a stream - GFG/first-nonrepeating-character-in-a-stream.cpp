//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char> st;
		    vector<int> vec(26,0);
		    string answer;
		    for(int i=0;i<A.length();i++){
		        vec[A[i]-'a']++;
		        if(vec[A[i]-'a']==1){
		            st.push(A[i]);
		        }
		        while(!st.empty() && vec[st.front()-'a']!=1){
		            st.pop();
		        }
		        if(st.empty()){
		            answer.push_back('#');
		        }
		        else{
		            answer.push_back(st.front());
		        }
		    }
		    return answer;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends