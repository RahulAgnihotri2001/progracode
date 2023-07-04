//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        // reverse the array
        // pick assending sequence
        Node* pre=NULL;
        Node* curr=head;
        Node* ne=head->next;
        while(ne!=NULL){
            curr->next=pre;
            pre=curr;
            curr=ne;
            ne=ne->next;
        }
        curr->next=pre;
        head=curr;
        while(curr->next!=NULL){
            if(curr->next->data >= curr->data){
                curr=curr->next;
            }
            else{
                curr->next=curr->next->next;
            }
        }
        pre=NULL;
        curr=head;
        ne=head->next;
        while(ne!=NULL){
            curr->next=pre;
            pre=curr;
            curr=ne;
            ne=ne->next;
        }
         curr->next=pre;
        return curr;
    }
    
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends