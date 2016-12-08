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
    ListNode* removeElements(ListNode* head, int val) 
    {
        if(NULL == head){
            return NULL;
        }
        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;
        
        while(NULL != head){
            if(val != head->val){
                temp->next = head;
                temp = temp->next;
            }
            head = head->next;
        }
        temp->next = NULL;
        return newHead->next;
    }
};
