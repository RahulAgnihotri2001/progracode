//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int answer=0;
        int count=0;
        queue<pair<int,pair<int,int>>> st;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    st.push({0,{i,j}});
                }
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        while(!st.empty()){
            int time=st.front().first;
            int i=st.front().second.first;
            int j=st.front().second.second;
            st.pop();
            // top
            if(i-1>=0 && grid[i-1][j]==1){
                answer=time+1;
                //cout<<time+1<<" "<<i<<" "<<j<<endl;
                st.push({time+1,{i-1,j}});
                grid[i-1][j]=2;
                count--;
            }
            // bottom
            if(i+1<n && grid[i+1][j]==1){
                answer=time+1;
                st.push({time+1,{i+1,j}});
                grid[i+1][j]=2;
                count--;
               // cout<<time<<" "<<i<<" "<<j<<endl;
            }
            // left
            if(j-1>=0 && grid[i][j-1]==1){
                answer=time+1;
                st.push({time+1,{i,j-1}});
                grid[i][j-1]=2;
                count--;
              //  cout<<time<<" "<<i<<" "<<j<<endl;
            }
            //right
            if(j+1<m && grid[i][j+1]==1){
                answer=time+1;
                st.push({time+1,{i,j+1}});
                grid[i][j+1]=2;
                count--;
             //   cout<<time<<" "<<i<<" "<<j<<endl;
            }
        }
        if(count!=0){
            return -1;
        }
        return answer;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends