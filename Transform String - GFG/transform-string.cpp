//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        int i=A.length()-1;
        int j=B.length()-1;
        if(i!=j){
            return -1;
        }
        map<char,int>vec1;
        map<char,int> vec2;
        for(int k=0;k<A.length();k++){
            vec1[A[k]]++;
            vec2[B[k]]++;
        }
        if(vec1!=vec2){
            return -1;
        }
        int answer=0;
        while(i>=0){
            if(A[i]==B[j]){
                i--;
                j--;
            }
            else{
                i--;
                answer++;
            }
        }
        return answer;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends