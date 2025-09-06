/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node * detectCycle(Node *head) {
        Node* slow=head;
        Node* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            } 
        }
        return NULL;
    }
    int lengthOfLoop(Node *head) {
        // code here
        Node* l=detectCycle(head);
        if(!l) return 0;
        int c=1;
        Node* n=l->next;
        while(n!=l){
            c++;
            n=n->next;
        }
        return c;
    }
};