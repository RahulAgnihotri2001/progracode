//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void fun(int i ,int j ,string &str,vector<vector<int>> &m,vector<string> &answer){
        if(i==m.size()-1 && j==m.size()-1){
            answer.push_back(str);
            return;
        }
        m[i][j]=2;
        // going top
        if(i-1>=0 && m[i-1][j]==1){
            str.push_back('U');
            fun(i-1,j,str,m,answer);
            str.pop_back();
        }
        // bottom
        if(i+1<m.size() && m[i+1][j]==1){
            str.push_back('D');
            fun(i+1,j,str,m,answer);
            str.pop_back();
        }
        // left
        if(i-1>=0 && m[i][j-1]==1){
            str.push_back('L');
            fun(i,j-1,str,m,answer);
            str.pop_back();
        }
        // right
        if(j+1<m.size() && m[i][j+1]==1){
            str.push_back('R');
            fun(i,j+1,str,m,answer);
            str.pop_back();
        }
        m[i][j]=1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
    vector<string> answer;
    if(m[0][0]==0){
        return answer;
    }
    string str="";
    fun(0,0,str,m,answer);
    return answer;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends