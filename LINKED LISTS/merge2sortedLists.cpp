//21. Merge 2 sorted lists Leetcode easy
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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode * head3= new ListNode();
        
        if(head1==NULL) return head2;
        else if(head2==NULL) return head1;
        
        if(head1->val <= head2->val){
            head3=head1;
            head1=head1->next;
        }else{
            head3=head2;
            head2=head2->next;
        }
        ListNode * help=head3;
        while(head1!=NULL && head2!=NULL){
            if(head1->val <= head2->val){
                help->next=head1;
                help=help->next;
                head1=head1->next;
            }else{
                help->next=head2;
                help=help->next;
                head2=head2->next;
            }
        }
        while(head1!=NULL){
            help->next=head1;
            help=help->next;
            head1=head1->next;
        }
        while(head2!=NULL){
            help->next = head2;
            help=help->next;
            head2=head2->next;
        }
        return head3;
        
    }
};