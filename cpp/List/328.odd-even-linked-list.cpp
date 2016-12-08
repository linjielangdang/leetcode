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
    ListNode* oddEvenList(ListNode* head) {
        if(NULL == head){
            return head;
        }
        ListNode* even = new ListNode(0);
        ListNode* evenBak = even;
        ListNode* odd = head;
        while(NULL != odd){
            if(NULL != odd->next){
                even->next = odd->next;
                even = even->next;
                if(NULL == odd->next->next){
                    even->next = NULL;
                    odd->next = evenBak->next;
                    break;
                }
                else{
                    odd->next = odd->next->next;
                    odd = odd->next;
                }
            }
            else{
                even->next = NULL;
                odd->next = evenBak->next;
                break;
            }
        }
        
        return head;
    }
};
