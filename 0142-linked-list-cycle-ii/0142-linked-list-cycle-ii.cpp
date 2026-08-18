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
        if(head == NULL) return NULL;
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;
        bool hasCycle = false;
        while(fast->next!=NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                hasCycle = true;
                break;
            }
        }
        if(!hasCycle){
            return NULL;
        }
        fast = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};