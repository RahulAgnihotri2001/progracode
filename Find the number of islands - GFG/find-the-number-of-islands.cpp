//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    void dfs(int i ,int j,vector<vector<char>>& grid){
        grid[i][j]='2';
        //top
        if(i-1>=0 && grid[i-1][j]=='1'){
            dfs(i-1,j,grid);
        }
        if(i-1>=0 && j-1>=0 && grid[i-1][j-1]=='1'){
             dfs(i-1,j-1,grid);
        }
        if(j-1>=0 && grid[i][j-1]=='1'){
            dfs(i,j-1,grid);
        }
        if(i-1>=0 && j+1<grid[0].size() && grid[i-1][j+1]=='1' ){
            dfs(i-1,j+1,grid);
        }
        if(j+1<grid[0].size() && grid[i][j+1]=='1'){
            dfs(i,j+1,grid);
        }
        if(i+1<grid.size() && grid[i+1][j]=='1'){
            dfs(i+1,j,grid);
        }
        if(i+1<grid.size() && j-1>=0 && grid[i+1][j-1]=='1'){
            dfs(i+1,j-1,grid);
        }
        if(i+1<grid.size() && j+1<grid[0].size() && grid[i+1][j+1]=='1'){
            dfs(i+1,j+1,grid);
        }
    }
  
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends