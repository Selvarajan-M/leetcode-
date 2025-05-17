/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* prev = NULL;
        ListNode* current = head;
         while (current != NULL) {
             while (current != NULL) {
            ListNode* nextNode = current->next; // store next node
            current->next = prev;               // reverse the link
            prev = current;                     // move prev forward
            current = nextNode;                 // move current forward
        }
         }
        return prev; // new head // new head
    }
};