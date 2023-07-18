//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> coin={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> answer;
        reverse(coin.begin(),coin.end());
        for(int i=0;i<coin.size();i++){
            while(N>=coin[i]){
                answer.push_back(coin[i]);
                N=N-coin[i];
            }
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends