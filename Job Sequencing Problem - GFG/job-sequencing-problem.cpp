//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool fun(Job &a , Job &b){
        if(a.profit!=b.profit){
           return a.profit > b.profit;
        }
        else{
            return a.dead>b.dead;
        }
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,fun);
        int m=0;
        for(int i=0;i<n;i++){
            m=max(m,arr[i].dead);
        }
        vector<int> st(m+1,-1);
        int count=0;
        int answer=0;
        for(int i=0;i<n;i++){
            if(st[arr[i].dead]==-1){
                count++;
                answer=answer+arr[i].profit;
                st[arr[i].dead]=0;
            }
            else{
                while(arr[i].dead>0 && st[arr[i].dead]!=-1){
                    arr[i].dead--;
                }
                if(arr[i].dead>0){
                    st[arr[i].dead]=0;
                    count++;
                    answer=answer+arr[i].profit;
                }
            }
        }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(answer);
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends