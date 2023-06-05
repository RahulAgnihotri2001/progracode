//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int a=-1;
        vector<int> answer;
        for(int i=0;i<n;i++){
            arr[abs(arr[i])-1]=arr[abs(arr[i])-1]*a;
        }
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                answer.push_back(i+1);
            }
        }
        int flag=0;
        //cout<<answer[0]<<"  "<<answer[1]<<endl;
        for(int i=0;i<n;i++){
            if(abs(arr[i])==answer[0]){
                flag=1;
                //cout<<"found : "<<answer[0]<<endl;
                break;
            }
        }
        //cout<<flag<<endl;
        if(flag==0){
            swap(answer[0],answer[1]);
        }
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends