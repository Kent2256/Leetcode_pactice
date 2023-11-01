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
lass Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* cur;
        cur = head;
        int val1,val2;
        val1 = 51;
        val2 = 51;
        while ((list1 != nullptr) || (list2 != nullptr)){
            if (list1 == nullptr){
                val1 = 51;
                val2 = list2->val;
            }else if (list2 == nullptr){
                val1 = list1->val;
                val2 = 51;
            }else{
                val1 = list1->val;
                val2 = list2->val;
            }
            if (val1 <= val2){
                ListNode* newNode = new ListNode(val1);
                cur->next = newNode;
                list1 = list1->next;
                cur = cur->next;
            }else{
                ListNode* newNode = new ListNode(val2);
                cur->next = newNode;
                list2 = list2->next;
                cur = cur->next;
            }
        }
        return head->next;
    }
};