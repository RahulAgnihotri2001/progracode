//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
    int dp(int index,int arr[],vector<int> &vec,int n){
        if(index>=n){
            return 0;
        }
        if(vec[index]!=-1){
            return vec[index];
        }
        int x= arr[index]+dp(index+2,arr,vec,n);
        int y= dp(index+1,arr,vec,n);
        vec[index]=max(x,y);
        return vec[index];
    }
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> vec(n,-1);
        return dp(0,arr,vec,n);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends