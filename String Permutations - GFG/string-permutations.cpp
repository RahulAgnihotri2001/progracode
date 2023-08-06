//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void fun(int index,string &s,vector<string> &vec){
        if(index==s.length()){
            vec.push_back(s);
            return;
        }
        //sort(s.begin()+index,s.end());
        for(int i=index;i<s.length();i++){
            swap(s[index],s[i]);
            fun(index+1,s,vec);
            swap(s[index],s[i]);
        }
    }
    
    
    vector<string> permutation(string S)
    {
        vector<string> answer;
        // sort(S.begin(),S.end());
        int index=0;
        fun(index,S,answer);
        sort(answer.begin(),answer.end());
        return answer;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends