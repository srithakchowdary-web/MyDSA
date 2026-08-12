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
    ListNode*  reverse(ListNode* head, ListNode* temp, ListNode* prev,int k, int c, int first){
        if(c==0)  return head;
        //`ListNode* connect = prev;
        ListNode* temp1 = temp;
        ListNode* curr = temp1;
        ListNode* previous = NULL;
        int count = k;
        while( count > 0){
            ListNode* nxt = curr->next;
            curr->next = previous;
            previous = curr;
            curr = nxt;
            --count;
        }
        if(prev != NULL)  prev->next = previous; //this line
        if(first == c){
            head = previous;
        }
        temp1->next = curr;
        reverse(head,curr, temp1, k, c-1,first);
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* temp = head;
        int  n =0;
        while(temp){
            n+=1;
            temp = temp->next;
        }
        int c = n/k ;
        return reverse(head, head, NULL, k,c,c);
    }
};