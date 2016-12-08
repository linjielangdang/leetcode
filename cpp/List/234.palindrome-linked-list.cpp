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
    bool isPalindrome(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(NULL != temp){
            ++len;
            temp = temp->next;
        }
        if(0 == len){
            return true;
        }
        
        ListNode* newHead = new ListNode(0);
        
        for(int i = 0; i < len/2; ++i){
            temp = head;
            head = head->next;
            temp->next = newHead->next;
            newHead->next = temp;
        }
        
        if(0 != len%2){
            head = head->next;
        }
        newHead = newHead->next;
        while(NULL != head){
            if(newHead->val != head->val){
                return false;
            }
            head = head->next;
            newHead = newHead->next;
        }
        
        return true;
    }
};
