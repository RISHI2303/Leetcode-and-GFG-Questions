// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node *partition(struct Node *head, int x) {
    // code here
    vector <int> small, large;
    int equalNodes = 0;

    Node *temp = head;

    while(temp) {
        if(temp->data < x)
            small.push_back(temp->data);

        else if(temp->data > x)
            large.push_back(temp->data);

        else
            equalNodes++;

        temp = temp->next;
    }

    temp = new Node(-1);
    Node *ans = temp;


    for (int i = 0; i < small.size(); i++){
        temp->next = new Node(small[i]);
        temp = temp->next;
    }

    while(equalNodes--){
        temp->next = new Node(x);
        temp = temp->next;
    }

    for (int i = 0; i < large.size(); i++) {
        temp->next = new Node(large[i]);
        temp = temp->next;
    }

    return ans->next;
}