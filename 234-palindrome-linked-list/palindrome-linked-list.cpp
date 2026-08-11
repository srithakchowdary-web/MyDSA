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
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        int n=0;
        while(temp){
            ++n;
            temp = temp->next;
            //++n;
        }
        temp = head;
        for(int i=0;i<n/2; ++i){
            temp = temp->next;
        }
        if(n%2 != 0)  temp=temp->next;
        ListNode* curr = temp;
        ListNode* prev = NULL;
        // to reverse the 2nd half of the linked list
        while(curr){
            ListNode* nxt = curr->next;
            curr->next=prev;
            prev = curr;
            curr = nxt;
        }
        //now check the equality
        ListNode* temp1= prev;
        temp = head;
        while(temp1){
            if(temp1->val != temp->val)  return false;
            temp1 = temp1->next;
            temp = temp->next;
        }
        return true;

    }
};