/*Linked list Node structure

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

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        vector<int> ans;
        for(auto i:arr)
            while(i){
                ans.push_back(i->data);
                i=i->next;
            }
        sort(ans.begin(), ans.end());
        Node* dummy=new Node(-1);
        Node* head=dummy;
        for(auto i:ans){
            dummy->next=new Node(i);
            dummy=dummy->next;
        }
        return head->next;
    }
};

