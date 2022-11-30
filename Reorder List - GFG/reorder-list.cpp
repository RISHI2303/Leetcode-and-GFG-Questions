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
        // base condition for a list containing 1 or 2 nodes
        if(head->next==NULL || head->next->next==NULL)
        return ;
        
        Node * slow=head, *fast=head;
        
        // Fast and slow pointer to find mid of the list
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        // if no of nodes are even then this is required to get the 
        // correct node as mid node
        if(fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next;
        }      
        
        // reversing the half linked list
        if(slow->next!=NULL)
            fast=slow->next;
            
        slow->next=NULL;
        
        while(1) {
            if(fast->next==NULL) {
                fast->next=slow;
                break;
            }
          
            else {
                Node*temp=fast->next;
                fast->next=slow;
                slow=fast;
                fast=temp;
            }
            
        }
        
        //Final adjusments in the list.
        slow=head;
        // 2 additional pointers for manipulation
        Node *temp1, *temp2;
        while(fast->next!=NULL) {
            temp1=slow->next;
            slow->next=fast;
            temp2=fast->next;
            fast->next=temp1;
            slow=temp1;
            fast=temp2;
        }
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