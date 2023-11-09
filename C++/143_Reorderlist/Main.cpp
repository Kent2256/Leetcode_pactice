// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.
//Input: head = [1,2,3,4,5,6]
// 1,6,2,5,3,4 
//Output: [1,5,2,4,3]

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
    void reorderList(ListNode* head) {
        ListNode *fast = nullptr;
        ListNode *slow = nullptr;
        fast = slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *nextnode = nullptr;
        ListNode *newnode = nullptr;
        ListNode *newhead = nullptr;
        newhead  = slow->next;
        slow->next = nullptr;
        while(newhead){
            nextnode = newhead->next;
            newhead->next = newnode;
            newnode = newhead;
            newhead = nextnode;
        }
        ListNode *temp1 = nullptr;
        int count = 0;
        while(head){
            if(count%2 == 0){
                if(not newnode)break;
                temp1= head->next;
                head->next=newnode;
                head = head->next;
            }
            else{
                newnode = head->next;
                head->next=temp1;
                head = head->next;
            }
            count++;
        }  
    }
};