/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reversell(ListNode* head){
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;

        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next->next != NULL){
            slow=slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = reversell(slow->next);
        int maxi = 0;
        ListNode* temp1 = head;
        ListNode* temp2 = head2;
        while(temp2 != NULL){
            int res = temp1->val + temp2->val;
            maxi = max(maxi,res);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return maxi;
    }
};