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

    ListNode* reverseLL(ListNode* head){
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

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* reverseHead = reverseLL(slow);

        while(reverseHead!=NULL){
            if(head->val != reverseHead->val) return false;
            head = head->next;
            reverseHead = reverseHead->next;
        }
        return true;
    }
};