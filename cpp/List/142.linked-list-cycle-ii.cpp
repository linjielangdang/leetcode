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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slowNode = head;
        ListNode *fastNode = head;
    
        while(NULL != slowNode){
            slowNode = slowNode->next;
            if(NULL != fastNode && NULL != fastNode->next){
                fastNode = fastNode->next->next;
            }
            else{
                return NULL;
            }
            
            if(fastNode == slowNode){
                ListNode *meetNode = slowNode;
                while(meetNode != head){
                    meetNode = meetNode->next;
                    head = head->next;
                }
                return head;
            }
        }
        
        return NULL;
    }
};
