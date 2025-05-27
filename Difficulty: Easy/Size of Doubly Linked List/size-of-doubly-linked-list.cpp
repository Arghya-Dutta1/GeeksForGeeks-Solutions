// User function Template for C++
class Solution {
  public:
    int findSize(Node *head) {
        // Code Here
        int s=0;
        while(head){
            s++;
            head=head->next;
        }
        return s;
    }
};