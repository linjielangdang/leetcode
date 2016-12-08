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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(NULL == head){
            return head;
        }
        int len = 0;
        ListNode *temp = head;
        while(NULL != temp){
            ++len;
            temp = temp->next;
        }
    
        if(0 == len-n){
            return head->next;
        }
        
        temp = head;
        ListNode *ret = temp;
        for(int i = 1; i < len-n; ++i){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        
        return ret;
    }
};
