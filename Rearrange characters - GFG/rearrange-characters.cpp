//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string str)
    {
        //find invalid case
        vector<int> vec(26,0);
        int n=str.length();
        for(int i=0;i<n;i++){
            vec[str[i]-'a']++;
        }
        if(n%2==1){
            n=n/2+1;
        }
        else{
            n=n/2;
        }
        for(int i=0;i<26;i++){
            if(vec[i]>n){
                return "-1";
            }
        }
        priority_queue<pair<int,int>> pq;   // 
        for(int i=0;i<26;i++){
            if(vec[i]!=0){
                pq.push({vec[i],i});
            }
        }
        string answer="";
        pair<int,int> hold;
        hold=pq.top();
        pq.pop();
        answer.push_back(char(hold.second+'a'));
        hold.first--;
        while(!pq.empty()){
            pair<int,int> ho=pq.top();
            pq.pop();
            answer.push_back(char(ho.second+'a'));
            ho.first--;
            if(hold.first>0){
                pq.push(hold);
            }
            hold=ho;
        }
        if(hold.first>0){
            answer.push_back(char(hold.second+'a'));
        }
        return answer;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends