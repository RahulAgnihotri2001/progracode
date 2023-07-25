//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        string answer="";
        int range_upper= 9*D;
        int range_lower=1;
        if(S<range_lower || S>range_upper){
            return "-1";
        }
        if(D==1){
            answer.push_back(char(S+'0'));
            return answer;
        }
        while(S>0){
            if(S>9){
                answer.push_back('9');
                S=S-9;
            }
            else if(S<=9 && answer.length()==D-1){
                char x= char(S+'0');
                answer.push_back(x);
                break;
            }
            else{
                char x= char(S-1 +'0');
                answer.push_back(x);
                while(answer.length()<D-1){
                    answer.push_back('0');
                }
                answer.push_back('1');
                break;
            }
        }
        reverse(answer.begin(),answer.end());
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
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends