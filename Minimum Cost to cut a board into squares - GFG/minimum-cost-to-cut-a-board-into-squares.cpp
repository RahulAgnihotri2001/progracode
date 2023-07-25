//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        //Write your code here
        sort(X.begin(),X.end());
        sort(Y.begin(),Y.end());
        int xnekiya=1;
        int ynekiya=1;
        int i=X.size()-1;
        int j=Y.size()-1;
        int answer=0;
        while(i>=0 ||j>=0){
            if(X[i]>=Y[j]){
                answer=answer+ynekiya*X[i];
                i--;
                xnekiya++;
            }
            else{
                answer=answer+xnekiya*Y[j];
                 j--;
                ynekiya++;
            }
        }
        while(i>=0){
              answer=answer+ynekiya*X[i];
                i--;
        }
         while(j>=0){
              answer=answer+xnekiya*Y[j];
                j--;
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
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends