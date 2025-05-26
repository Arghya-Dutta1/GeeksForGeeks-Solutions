/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* tmp=head;
        while(tmp){
            if(data<=tmp->data){
                int nd=tmp->data;
                tmp->data=data;
                Node* d=new Node(nd);
                d->next=tmp->next;
                tmp->next=d;
                break;
            }
            else if(tmp->data>tmp->next->data){
                Node* d=new Node(data);
                d->next=tmp->next;
                tmp->next=d;
                break;
            }
            tmp=tmp->next;
        }
        return head;
    }
};