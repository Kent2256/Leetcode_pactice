class Solution(object):
    def isPalindrome(self, head):
        val_list = []
        pos =head
        while pos:
            val_list.append(pos.val)
            pos = pos.next
        if val_list == val_list[::-1]:
            return True
        return False
    def isPalindrome(self, head):
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        if fast:
            slow = slow.next
        slow = self.reverse(slow)
        fast = head
        while slow:
            if slow.val != fast.val:
                return False
            slow = slow.next
            fast = fast.next
        return True
    def reverse(self, head):
        prev = None
        while head:
            curr = head
            head = head.next
            curr.next = prev
            prev = curr
        return prev