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
    ListNode* deleteDuplicates(ListNode* head) {
       if (NULL == head){
            return NULL;
       }
       ListNode* dummyNode = new ListNode(0);
       dummyNode->next = head;
       ListNode* p = dummyNode;
       while(NULL != p->next){
           int preVal = p->next->value;
           if (NULL != p->next)
       }
    }
};
