//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
  
    void fun(int index,vector<int>&A,vector<int> &inorder){
        if(index>=A.size()){
            return;
        }
        fun(index*2+1,A,inorder);
        inorder.push_back(A[index]);
        fun(index*2+2,A,inorder);
    }
  
    int minSwaps(vector<int>&A, int n){
        vector<int> inorder;
        int index=0;
        fun(index,A,inorder);
        vector<int> sorted=inorder;
        sort(sorted.begin(),sorted.end());
        unordered_map<int,int> mp;
        for(int i=0;i<sorted.size();i++){
            mp[sorted[i]]=i;
        }
        int answer=0;
        for(int i=0;i<inorder.size();i++){
            if(mp[inorder[i]]!=i){
                while(mp[inorder[i]]!=i){
                    swap(inorder[i],inorder[mp[inorder[i]]]);
                    answer++;
                }
            }
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
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends