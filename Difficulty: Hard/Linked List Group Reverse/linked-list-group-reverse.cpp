/*
class Node {
  public:
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
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if (k <= 1) return head;

        Node dummy(0);
        dummy.next = head;
        Node* prev = &dummy;

        while (true) {
            
            Node* end = prev;
            int count = 0;
            
            while (count < k && end->next != nullptr) {
                end = end->next;
                count++;
            }

            if (count == 0) break;  

            Node* start = prev->next;
            Node* next = end->next;

            reverse(start, next);   

            prev->next = end;      
            start->next = next;     

            prev = start;          

            if (count < k) break;    
        }

        return dummy.next;
    }

private:
    void reverse(Node* head, Node* stop) {
        Node* prev = stop;
        while (head != stop) {
            Node* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
    }
};