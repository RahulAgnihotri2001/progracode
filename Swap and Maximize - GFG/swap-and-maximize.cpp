//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    int start=1;
    int end=n-2;
    while(start<=end){
        swap(arr[start],arr[end]);
        start=start+2;
        end=end-2;
    }
    long long int answer=arr[n-1]-arr[0];
    for(int i=0;i<n-1;i++){
       // cout<<arr[i]<<" , ";
        answer=answer+abs(arr[i+1]-arr[i]);
    }
    return answer;
    
}