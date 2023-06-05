//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    sort(arr,arr+size);
    for(int i=0;i<size-1;i++){
        int x = n+arr[i];
        int start=i+1;
        int end=size-1;
        while(start<end){
            int mid=start+(end-start)/2;
            if(arr[mid]>=x){
                end=mid;
            }
            else{
                start=mid+1;
            }
        }
        if(arr[start]==x){
            return true;
        }
    }
    return false;
}