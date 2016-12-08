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
    ListNode* swapPairs(ListNode* head) {
        if(NULL == head){
            return head;
        }
        int temp;
        ListNode *node = head->next, *preNode = head;
        while(NULL != preNode){
            if(NULL == node){
                break;
            }
            temp = node->val;
            node->val = preNode->val;
            preNode->val = temp;
            if(NULL != node->next){
                preNode = node->next;
                node = preNode->next; 
            }
            else{
                preNode = NULL;
                node = NULL; 
            }
            
        }
        return head;
    }
};
