//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    queue<pair<int,int>> qu;
	    int n=grid.size();
	    int m=grid[0].size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                qu.push({i,j});
	            }
	        }
	    }
	    while(!qu.empty()){
	        int i=qu.front().first;
	        int j=qu.front().second;
	        qu.pop();
	        if(i+1 <n && grid[i+1][j]==0){
	            grid[i+1][j]=grid[i][j]+1;
	            qu.push({i+1,j});
	        }
	        if (j+1<m && grid[i][j+1]==0){
	            grid[i][j+1]=grid[i][j]+1;
	            qu.push({i,j+1});
	        }
	        if(i-1 >=0  && grid[i-1][j]==0){
	            grid[i-1][j]=grid[i][j]+1;
	            qu.push({i-1,j});
	        }
	        if( j-1>=0 && grid[i][j-1]==0){
	            grid[i][j-1]=grid[i][j]+1;
	            qu.push({i,j-1});
	        }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            grid[i][j]--;
	        }
	    }
	    return grid;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends