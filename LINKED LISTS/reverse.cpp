//REVERSE A LINKED LIST
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* p=NULL;
        ListNode* q=head;
        ListNode* r=head->next;
        
        while(r!=NULL){
            q->next=p;
            p=q;
            q=r;
            r=r->next;
        }
        q->next=p;

        return q;
    }
};