//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

 static bool fun(Item &a,Item &b){
     double x=double(a.value)/double(a.weight);
     double y=double(b.value)/double(b.weight);
    return x>y;
 }

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,fun);
        double answer=0;
        int index=0;
        while(w>0 && index<n){
            if(w>=arr[index].weight){
                answer=answer+arr[index].value;
                w=w-arr[index].weight;
                index++;
            }
            else{
                double wei=arr[index].weight;
                double val=arr[index].value;
                double pri=val/wei;
                answer=answer+w*pri;
                break;
            }
        }
        return answer;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends