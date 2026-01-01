/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int length(Node* head) {
        int cnt = 0;
        while (head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    Node* intersectPoint(Node* head1, Node* head2) {
        int len1 = length(head1);
        int len2 = length(head2);

        Node* p1 = head1;
        Node* p2 = head2;
        if (len1 > len2) {
            int diff = len1 - len2;
            while (diff--) p1 = p1->next;
        } else {
            int diff = len2 - len1;
            while (diff--) p2 = p2->next;
        }
        while (p1 && p2) {
            if (p1 == p2)
                return p1;
            p1 = p1->next;
            p2 = p2->next;
        }

        return NULL;
    }
};
