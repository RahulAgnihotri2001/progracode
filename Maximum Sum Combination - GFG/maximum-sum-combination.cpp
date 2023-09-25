//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        
        // want max heap of type {sum,i,j};
        // set to make sure no repetation pair
        // sort both the arrays
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        priority_queue<pair<int,pair<int,int>>> pq;
        vector<int> answer;
        int i=N-1;
        int j=N-1;
        int x=A[i]+B[j];
        answer.push_back(x);
        K--;
        set<pair<int,int>> st;
        st.insert({i,j});
        pq.push({A[i-1]+B[j],{i-1,j}});
        st.insert({i-1,j});
        pq.push({A[i]+B[j-1],{i,j-1}});
        st.insert({i,j-1});
        while(K!=0){
            int topsum=pq.top().first;
            int a=pq.top().second.first;
            int b=pq.top().second.second;
            answer.push_back(topsum);
            K--;
            pq.pop();
            if(st.find({a-1,b})==st.end()){
                pq.push({A[a-1]+B[b],{a-1,b}});
                st.insert({a-1,b});
            }
            if(st.find({a,b-1})==st.end()){
                pq.push({A[a]+B[b-1],{a,b-1}});
                st.insert({a,b-1});
            }
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends