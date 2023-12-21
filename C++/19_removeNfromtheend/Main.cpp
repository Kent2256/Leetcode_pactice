//Given the head of a linked list, remove the nth node from the end of the list and return its head.
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]

// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *end = nullptr;
        ListNode *pre_node = nullptr;
        pre_node = end = head;
        for(int i=0; i< n;i++)end= end->next;
        if(not end)return head->next;
        // move foward 1 step
        end = end->next;
        // travel to end
        while(end){
            end = end->next;
            pre_node = pre_node->next;
        }
        pre_node->next = pre_node->next->next;
        return head;
    }
};