//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool check(int x,int y ,vector<vector<char>> &mat){
        if(x<0 || y<0 || x>=mat.size() || y>=mat[0].size() || mat[x][y]!='O'){
            return false;    
       }
       return true;
    }


    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // store all the boundary 0  and do dfs on them and conver them to z 
        // now all the 0 left -> convert them to x   
        // convert all z to 0;
        stack<pair<int,int>> st;
        for(int i=0;i<mat.size();i++){
            if(mat[i][0]=='O'){
                st.push({i,0});
                mat[i][0]='1';
            }
        }
        for(int i=0;i<mat[0].size();i++){
            if(mat[0][i]=='O'){
                st.push({0,i});
                mat[0][i]='1';
            }
        }
        for(int i=0;i<mat.size();i++){
            if(mat[i][mat[0].size()-1]=='O'){
                st.push({i,mat[0].size()-1});
                mat[i][mat[0].size()-1]='1';
            }
        }
        for(int i=0;i<mat[0].size();i++){
            if(mat[mat.size()-1][i]=='O'){
                st.push({mat.size()-1,i});
                mat[mat.size()-1][i]='1';
            }
        }
        while(!st.empty()){
            int x=st.top().first;
            int y=st.top().second;
            st.pop();
            // left
                if(check(x,y-1,mat)){
                    mat[x][y-1]='1';
                    st.push({x,y-1});
                }
            
            //right
                if(check(x,y+1,mat)){
                    mat[x][y+1]='1';
                    st.push({x,y+1});
                }
            // top 
                if(check(x-1,y,mat)){
                    mat[x-1][y]='1';
                    st.push({x-1,y});
                }
            //bottom 
                if(check(x+1,y,mat)){
                    mat[x+1][y]='1';
                    st.push({x+1,y});
                }
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]=='O'){
                    mat[i][j]='X';
                }
                else if(mat[i][j]=='1'){
                    mat[i][j]='O';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends