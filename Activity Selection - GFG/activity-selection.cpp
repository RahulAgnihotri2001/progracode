//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    static bool fun(pair<int,int> &a,pair<int,int> &b){
        return a.second < b.second;
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int>> vec;
        for(int i=0;i<start.size();i++){
            vec.push_back({start[i],end[i]});
        }
        sort(vec.begin(),vec.end());
        sort(vec.begin(),vec.end(),fun);
       
        int prend=vec[0].second;
        int answer=1;
        for(int i=1;i<vec.size();i++){
            if(vec[i].first>prend){
                answer++;
                prend=vec[i].second;
            }
        }
        return answer;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends