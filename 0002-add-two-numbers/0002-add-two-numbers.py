# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummyHead=ListNode(0)
        curr=dummyHead
        carry=0
        while l1 or l2:
            val1=l1.val if l1 else 0
            val2=l2.val if l2 else 0
            carry,out=divmod(val1+val2+carry,10)
            curr.next=ListNode(out)
            curr=curr.next
            l1=l1.next if l1 else None
            l2=l2.next if l2 else None
        if(carry):
            curr.next=ListNode(carry)
        return dummyHead.next
            
         
       
            
        