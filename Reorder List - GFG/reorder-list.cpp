//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{ 
public:
    void reorderList(Node* head) {
        // Your code here
        Node* temp=head;
        int count=0;
        while(temp!=NULL){
            count++ ;
            temp=temp->next;
        }
        if(count==1 || count==2){
            return;
        }
        if(count%2==0){
            count=count/2;
        }
        else{
            count=count/2+1;
        }
        temp=head;
        int index=0;
        while(index!=count-1){
            index++;
            temp=temp->next;
        }
        Node* temp2=temp->next;
        //cout<< temp2->data<<" ++++ "<<endl;
        //Node* head2=temp2;
        temp->next=NULL;
        Node* pre=NULL;
        Node* ne=temp2->next;
        while(ne!=NULL){
            temp2->next=pre;
            pre=temp2;
            temp2=ne;
            ne=ne->next;
        }
        temp2->next=pre;
       // cout<< temp2->data<<" ++++ "<<endl;
        Node* head2=temp2;
        temp=head;
        // head=temp2;
        while(temp!=NULL){
            Node* t1=temp->next;
            temp->next=head2;
            temp=t1;
            if(head2!=NULL){
                t1=head2->next;
                head2->next=temp;
                head2=t1;
            }
        }

        return ;
    }
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends