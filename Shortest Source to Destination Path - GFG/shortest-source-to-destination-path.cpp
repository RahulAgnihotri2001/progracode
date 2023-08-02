//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]!=1){
            return -1;
        }
        queue<vector<int>> q;
        q.push({0,0,0});
        A[0][0]=2;
        while(!q.empty()){
            int i=q.front()[0];
            int j=q.front()[1];
            int jump=q.front()[2];
            q.pop();
            if(i==X && j==Y){
                return jump;
            }
            // right
            if(j+1<M && A[i][j+1]==1){
                q.push({i,j+1,jump+1});
                A[i][j+1]=2;
            }
            // down
            if(i+1<N && A[i+1][j]==1){
                q.push({i+1,j,jump+1});
                A[i+1][j]=2;
            }
            // left
            if(j-1>=0 && A[i][j-1]==1){
                q.push({i,j-1,jump+1});
                A[i][j-1]=2;
            }
            // top
            if(i-1>=0 && A[i-1][j]==1){
                q.push({i-1,j,jump+1});
                A[i-1][j]=2;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends