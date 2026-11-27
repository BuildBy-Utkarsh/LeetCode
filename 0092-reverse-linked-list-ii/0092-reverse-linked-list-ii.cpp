class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL) {
            return NULL;
        }
        if (left == right) {
            return head;
        }

        ListNode* t = head;
        ListNode* before = NULL;
        int pos = 1;

        while (t != NULL) {
            if (pos < left) {
                before = t;
                t = t->next;
                pos++;
                continue;
            } 

            ListNode* curr = t;
            ListNode* prev = NULL;
            int times = right - left + 1;

            while (times--) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            t->next = curr;

            if (before != NULL) {
                before->next = prev; 
                return head;
            } else {
                return prev;        
            }
        }

        return head;
    }
};
