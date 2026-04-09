class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy node
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        // Attach remaining
        if (list1 != NULL)
            temp->next = list1;
        else
            temp->next = list2;

        return dummy->next;
    }
};