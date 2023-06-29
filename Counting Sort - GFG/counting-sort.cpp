//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        // code here
        vector<int> vec(26,0);
        for(int i=0;i<arr.length();i++){
            vec[arr[i]-'a']++;
        }
        int sum=0;
        for(int i=0;i<26;i++){
            sum=sum+vec[i];
            vec[i]=sum;
        }
        string answer=arr;
        for(int i=0;i<arr.length();i++){
            char x=arr[i];
            int y=x-'a';
            answer[vec[y]-1]=x;
            vec[y]--;
        }
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
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}

// } Driver Code Ends