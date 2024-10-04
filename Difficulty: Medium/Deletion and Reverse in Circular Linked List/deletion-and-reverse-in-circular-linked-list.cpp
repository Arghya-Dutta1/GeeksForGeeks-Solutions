//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends

class Solution {
public:
    Node* reverse(Node* head) {
        if (!head || head->next == head) {
            return head;
        }

        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        Node* tail = head;

        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head);

        tail->next = prev;

        return prev;
    }

    Node* deleteNode(Node* head, int key) {
        if (!head) return nullptr;

        Node* current = head;
        Node* prev = nullptr;

        if (head->data == key) {
            if (head->next == head) {
                delete head;
                return nullptr;
            }

            Node* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }

            tail->next = head->next;
            Node* newHead = head->next;
            delete head;
            return newHead;
        }

        do {
            prev = current;
            current = current->next;
        } while (current != head && current->data != key);

        if (current->data == key) {
            prev->next = current->next;
            delete current;
        }

        return head;
    }
};


//{ Driver Code Starts.

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

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends