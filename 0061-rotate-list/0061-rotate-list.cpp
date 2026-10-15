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
    ListNode* reversell(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int sz(ListNode* head){
        ListNode* temp = head;
        int size= 0;
        while(temp!=NULL){
            size++;
            temp = temp->next;
        }
        return size;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int size = sz(head);
        k = k%size;
        if(k==0) return head;
        ListNode* newhead = reversell(head);
        ListNode* prev = NULL;
        ListNode* second = newhead;
        for(int i =0;i<k;i++){
            prev = second;
            second = second->next;
        }

        if(prev != NULL){
            prev->next = NULL;
        }

        ListNode* finallist = reversell(newhead);
        ListNode* finalhalf = reversell(second);

        newhead->next = finalhalf;
        return finallist;
    }
};