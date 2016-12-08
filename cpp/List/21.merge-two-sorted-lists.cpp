/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *head = new ListNode(0);
        ListNode *temp = head;
        while(NULL != p && NULL != q){
            if(p->val <= q->val){
                temp->next = p;
                temp = temp->next;
                p = p->next;
            }
            else{
                temp->next = q;
                temp = temp->next;
                q = q->next;
            }
        }
        
        if(NULL == p && NULL != q){
            temp->next = q;
        }
        if(NULL != p && NULL == q){
            temp->next = p;
        }
        
        return head->next;
    }
};
