//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    if(k==1){
	        return n;
	    }
	    int sum=0;
	    int answer=0;
	    map<int,int> mp;
	    mp[0]=-1;
	    
	    for(int i=0;i<n;i++){
	        sum=(sum+arr[i])%k;
	        // cout<<" Sum "<<sum<<", Index : "<<i<<endl;
	        if(sum<0){
	            while(sum<0)
	            sum=sum+k;
	        }
	        if(mp.find(sum)==mp.end()){
	            mp[sum]=i;
	        }
	        else{
	            answer=max(answer,i-mp[sum]);
	        }
	    }
	    /*
	    for(auto it : mp){
	        cout<<it.first<< " -> "<<it.second<<endl;
	    }*/
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
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends