//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        int ans=INT_MAX;
        pair<int,int> pr;
        int start=0;
        int end=m-1;
        vector<int> vec;
        while(start<n && end>=0){
            int y=arr[start]+brr[end];
            if(ans>abs(x-y)){
                pr={arr[start],brr[end]};
                ans=abs(x-y);
            }
            if(y>x){
                end--;
            }
            else{
                start++;
            }
        }
        vec={pr.first,pr.second};
        return vec;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends