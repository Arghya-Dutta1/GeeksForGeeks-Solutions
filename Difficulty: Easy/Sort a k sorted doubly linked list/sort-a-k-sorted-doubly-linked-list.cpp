//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/*
// a node of the doubly linked list
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // function to sort a k sorted doubly linked list
    struct compare
    {
        bool operator()(struct DLLNode *t1, struct DLLNode *t2)
        {
            return t1->data > t2->data;
        }
    };
    
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        // code here
        if (head == NULL) return head;

        priority_queue< DLLNode *, vector<DLLNode *>, compare> pq;

        DLLNode *newHead = NULL;
        DLLNode *last = NULL;

        for(int i=0; i<=k && head!=NULL; i++)
        {
            pq.push(head);
            head = head->next;
        }

        while (!pq.empty())
        {
            if (newHead == NULL)
            {
                newHead = pq.top();
                newHead->prev = NULL;
                last = newHead;
            }
            else
            {
                last->next = pq.top();
                pq.top()->prev = last;
                last = pq.top();
            }
            pq.pop();

            if (head != NULL)
            {
                pq.push(head);
                head = head->next;
            }
        }
        last->next = NULL;
        return newHead;
    }
};

//{ Driver Code Starts.

// Function to insert a node at the end
// of the Doubly Linked List
void push(DLLNode **tailRef, int new_data) {
    // allocate node
    DLLNode *newNode = new DLLNode(new_data);

    // since we are adding at the end,
    // next is NULL
    newNode->next = NULL;

    newNode->prev = (*tailRef);

    // change next of tail node to new node
    if ((*tailRef) != NULL)
        (*tailRef)->next = newNode;

    (*tailRef) = newNode;
}

// Function to print nodes in a given doubly linked list
void printList(DLLNode *head) {
    // if list is empty
    if (head == NULL)
        return;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Driver
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        int k;
        cin >> k;
        cin.ignore();

        DLLNode *head = new DLLNode(arr[0]);
        DLLNode *tail = head;

        // Check if the array is empty
        for (size_t i = 1; i < arr.size(); ++i) {
            push(&tail, arr[i]);
        }
        Solution obj;
        printList(obj.sortAKSortedDLL(head, k));
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends