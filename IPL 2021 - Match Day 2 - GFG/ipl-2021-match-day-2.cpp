//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        deque<int> dq;
        vector<int> answer;
        for(int i=0;i<k-1;i++){
            if(dq.empty()){
                dq.push_back(i);
            }
            else{
                while(!dq.empty() && arr[dq.back()]<arr[i]){
                    dq.pop_back();
                }
                dq.push_back(i);
            }
        }
        for(int i=k-1;i<n;i++){
            while(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            while(!dq.empty() && arr[dq.back()]<arr[i]){
                    dq.pop_back();
                }
            dq.push_back(i);
            answer.push_back(arr[dq.front()]);
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends