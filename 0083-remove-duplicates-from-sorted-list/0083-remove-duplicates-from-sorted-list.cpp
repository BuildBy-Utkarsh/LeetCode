class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            if (fast->val == fast->next->val) {
                fast->next = fast->next->next;
            }
            else {
                fast = fast->next;
            }
        }

        return head;
    }
};