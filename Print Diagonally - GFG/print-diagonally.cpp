//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDiagonal(int N, vector<vector<int>> A)
	{
		// Your code goes here
		vector<int> answer;
		for(int i=0;i<A.size();i++){
		    int a=i;
		    for(int j=0;j<=i;j++){
		        answer.push_back(A[j][a]);
		        a--;
		    }
		}
		for(int i=1;i<A.size();i++){
		    int a=i;
		    for(int j=A.size()-1;j>=i;j--){
		        answer.push_back(A[a][j]);
		        a++;
		    }
		}
		return answer;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDiagonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends