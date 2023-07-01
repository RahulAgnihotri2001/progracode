//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    void merge(long long start,long long end,long long arr[],long long &count){
        long long mid=start+(end-start)/2;
        int n1=mid-start+1;
        int n2=end-mid;
        // make arrays
        long long L[n1];
        long long R[n2];
        // copying values in arrays
        for(int i=0;i<n1;i++){
            L[i]=arr[i+start];
        }
        for(int i=0;i<n2;i++){
            R[i]=arr[i+mid+1];
        }
        int i=0 ,j =0,k=start;
        while(i<n1 && j<n2){
            if(L[i]<=R[j]){
                arr[k]=L[i];
                i++;
            }
            else{
                count=count+n1-i;
                //cout<<L[i]<<" with "<<R[j]<<endl;
                arr[k]=R[j];
                j++;
            }
            k++;
        }
        if(i<n1){
            while(i!=n1){
                arr[k]=L[i];
                i++;
                k++;
            }
        }
        if(j<n2){
            while(j!=n2){
                arr[k]=R[j];
                j++;
                k++;
            }
        }
    }
    
    void mergesort(long long start,long long end,long long arr[],long long &count){
        if(start<end){
            long long mid=start+(end-start)/2;
            mergesort(start,mid,arr,count);
            mergesort(mid+1,end,arr,count);
            merge(start,end,arr,count);
        }
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long start=0;
        long long end=N-1;
        long long count=0;
        mergesort(start,end,arr,count);
        return count;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends