//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    void insertHeap(int &x)
    {
        if(left.empty() && right.empty()){
            left.push(x);
        }   
        else if(!left.empty() && x<left.top()){
            left.push(x);
        }
        else{
            right.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        while(left.size()!=right.size() && abs(left.size()-right.size())!=1){
            if(left.size()>right.size()){
                int x=left.top();
                left.pop();
                right.push(x);
            }
            else{
                int y=right.top();
                right.pop();
                left.push(y);
            }
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(left.size()==right.size()){
            double a=left.top();
            double b=right.top();
            return (a+b)/2;
        }
        if(left.size()>right.size()){
            return left.top();
        }
        return right.top();
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends