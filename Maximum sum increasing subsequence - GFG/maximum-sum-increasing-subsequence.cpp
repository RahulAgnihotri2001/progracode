//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> sum(n,0);
	    sum[0]=arr[0];
	    for(int i=1;i<n;i++){
	        int ma=0;
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i]){
	                ma=max(ma,sum[j]);
	            }
	        }
	        sum[i]=arr[i]+ma;
	    }
	    int answer=0;
	    for(int i=0;i<sum.size();i++){
	        answer=max(answer,sum[i]);
	    }
	    return answer;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends