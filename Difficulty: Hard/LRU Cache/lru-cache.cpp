//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
  public:
    // Constructor for initializing the cache capacity with the given value.
    class node{
    public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int k, int v){
            key=k;
            val=v;
        }
    };

    node* head=new node(-1, -1);
    node* tail=new node(-1, -1);

    int cap;
    unordered_map<int, node*> mp;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void add(node* newnode) {
        node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }

    void del(node* delnode) {
        node * delprev = delnode -> prev;
        node * delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            node* resnode = mp[key];
            int res = resnode -> val;
            mp.erase(key);
            del(resnode);
            add(resnode);
            mp[key] = head -> next;
            return res;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            node* existingnode = mp[key];
            mp.erase(key);
            del(existingnode);
        }
        if (mp.size() == cap) {
            mp.erase(tail -> prev -> key);
            del(tail -> prev);
        }

        add(new node(key, value));
        mp[key] = head -> next;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends