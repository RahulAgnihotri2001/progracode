//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	    void fun(string s ,int index,set<string> &st){
	        if(index==s.length()-1){
	            st.insert(s);
	            return;
	        }
	        for(int i=index;i<s.length();i++){
	            swap(s[index],s[i]);
	            sort(s.begin()+index+1,s.end());
	            fun(s,index+1,st);
	            swap(s[index],s[i]);
	        }
	        return;
	        
	    }
	
		vector<string>find_permutation(string s)
		{
		    sort(s.begin(),s.end());
		    set<string> st;
		    vector<string> answer;
		    fun(s,0,st);
		    for(auto it : st){
		        answer.push_back(it);
		    }
		    return answer;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends