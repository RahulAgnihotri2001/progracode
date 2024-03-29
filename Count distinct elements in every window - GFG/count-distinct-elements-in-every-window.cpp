//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        vector<int> answer;
        unordered_map<int,int> mp;
        int start=0;
        for(int i=0;i<k;i++){
            mp[A[i]]++;
        }
        //cout<<"hello";
        answer.push_back(mp.size());
        for(int i=k;i<n;i++){
            mp[A[i]]++;
            if(mp[A[start]]==1){
                mp.erase(A[start]);
            }
            else{
                mp[A[start]]--;
            }
            start++;
            answer.push_back(mp.size());
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

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends