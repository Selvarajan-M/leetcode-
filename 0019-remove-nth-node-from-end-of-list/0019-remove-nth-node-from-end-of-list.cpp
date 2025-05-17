class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases (like deleting head)
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the target node
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        // Return new head
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
