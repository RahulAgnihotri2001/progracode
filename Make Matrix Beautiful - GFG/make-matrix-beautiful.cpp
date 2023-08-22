//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        int ma=0;
        for(int i=0;i<matrix.size();i++){
            int sum=0;
            for(int j=0;j<matrix[0].size();j++){
                sum=sum+matrix[i][j];
            }
            ma=max(sum,ma);
        }
        for(int i=0;i<matrix[0].size();i++){
            int sum=0;
            for(int j=0;j<matrix.size();j++){
                sum=sum+matrix[j][i];
            }
            ma=max(sum,ma);
        }
        int sum=0;
        for(int i=0;i<matrix.size();i++){
            int sum2=0;
            for(int j=0;j<matrix[0].size();j++){
                sum2=sum2+matrix[i][j];
            }
            sum=sum+ma-sum2;
        }
        for(int i=0;i<matrix[0].size();i++){
            int sum2=0;
            for(int j=0;j<matrix.size();j++){
                sum2=sum2+matrix[j][i];
            }
            sum=sum+ma-sum2;
        }
        return sum/2;
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends