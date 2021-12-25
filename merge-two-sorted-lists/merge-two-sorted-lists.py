# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        res = ListNode()
        
        if (list1 == None):
            return list2
        if (list2 == None):
            return list1
        
        iter1 = list1
        iter2 = list2
        
        ptr = res
        
        while (iter1 != None and iter2 != None):
            if (iter1.val < iter2.val):
                ptr.next = ListNode(iter1.val)
                iter1 = iter1.next
            else:
                ptr.next = ListNode(iter2.val)
                iter2 = iter2.next
            ptr = ptr.next
                
        while (iter1 != None):
            ptr.next = ListNode(iter1.val)
            iter1 = iter1.next
            ptr = ptr.next
        
        while (iter2 != None):
            ptr.next = ListNode(iter2.val)
            iter2 = iter2.next
            ptr = ptr.next
            
        return res.next
            