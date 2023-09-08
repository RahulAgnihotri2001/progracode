//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        // to use stack;
        unordered_set<int> st;
        vector<int> answer;
        queue<int> qu;
        st.insert(0);
        qu.push(0);
        answer.push_back(0);
        while(!qu.empty()){
            int x=qu.front();
            qu.pop();
            for(int i=0;i<adj[x].size();i++){
                if(st.find(adj[x][i])==st.end()){
                    st.insert(adj[x][i]);
                    qu.push(adj[x][i]);
                    answer.push_back(adj[x][i]);
                }
            }
        }
        return answer;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends