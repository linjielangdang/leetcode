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
    bool hasCycle(ListNode *head) {
        if(NULL == head){
            return false;
        }
        ListNode *fastNode = head;
        ListNode *slowNode = head;
        while(NULL != slowNode){
            slowNode = slowNode->next;
            if(NULL != fastNode && NULL != fastNode->next){
                fastNode = fastNode->next->next;
            }
            else{
                return false;
            }
            if(NULL != slowNode && NULL != fastNode && slowNode->val == fastNode->val){
                return true;
            }
        }
        return false;
    }
};
