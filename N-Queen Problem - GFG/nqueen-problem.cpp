//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool check(int i,int j ,vector<vector<int>> &board){
        int n=board.size();
        for(int a=0;a<i;a++){
            if(board[a][j]==1){
                return false;
            }
        }
        int row=i-1;
        int col=j-1;
        while(row>=0 && col>=0){
            if(board[row][col]==1){
                return false;
            }
            row--;
            col--;
        }
        row=i-1;
        col=j+1;
        while(row>=0 && col<n){
            if(board[row][col]==1){
                return false;
            }
            row--;
            col++;
        }
        return true;
    }

    void fun(int row ,int size ,vector<vector<int>> &answer,vector<int> &temp,vector<vector<int>> &board){
        if( row>=size){
        answer.push_back(temp);
        return;
        }
        for(int i=0;i<size;i++){
            board[row][i]=1;
            if(check(row,i,board)){
                temp.push_back(i+1);
                fun(row+1,size,answer,temp,board);
                temp.pop_back();
            }
            board[row][i]=0;
        }
        return;
    }

    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> answer;
        vector<int> temp;
        vector<vector<int>> board(n,vector<int>(n,0));
        fun(0,n,answer,temp,board);
        return answer;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends