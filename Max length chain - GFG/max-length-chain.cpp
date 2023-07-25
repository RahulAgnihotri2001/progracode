//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

static bool fun(val &a,val &b){
    return a.second<b.second;
}

class Solution{
public:
    /*You are required to complete this method*/
    int maxChainLen(struct val p[],int n){
        //Your code here
        sort(p,p+n,fun);
        int answer=1;
        int end=p[0].second;
        int index=1;
        while(index<n){
            if(p[index].first>end){
                answer++;
                end=p[index].second;
            }
            index++;
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends