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
        ListNode* res = head;
        while(NULL != head){
            while (NULL != head->next && head->val == head->next->val){
                ListNode* temp = head->next;
                head->next = head->next->next;
                delete(temp);
                temp = NULL;
            }
            head = head->next;
        }
        return res;
    }
};
