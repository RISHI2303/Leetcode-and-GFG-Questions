// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

int countNodesinLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        cout<< countNodesinLoop(head) << endl;
    }
	return 0;
}
// } Driver Code Ends


/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    // Code here
    if(!head || !head->next || !head->next->next) // agr ye 3 m se ek bhi null ho gya mtlb loop nhi h
        return 0;

    struct Node *slow = head->next, *fast = head->next->next;

    while(fast && fast->next) { // jab tak fast ya fast->next null nhi ho jata
        if(slow == fast) // agr slow aur fast meet kr gye to loop break
            break;

        slow = slow->next; // slow with one node speed
        fast = fast->next->next; // fast with 2 nodes speed
    }

    if(!fast || !fast->next) // agr fast ya fast->next null ho gya mtlb loop nhi h
        return 0;

    // ab kyuki pta lag gya h ki loop exists. So we'll initialize a count variable from 1
    // aur fast ko vhi rkhenge
    // jab tak fast aur slow nhi milte, increment count
    int count = 1;
    slow = slow->next;

    while (slow != fast) {
        count++;
        slow = slow->next;
    }

    return count;
}