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
//2. Add Two Numbers
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode * head3=new ListNode();
        ListNode * temp= head3;
        int carry=0;
        while(head1!=NULL || head2!=NULL || carry==1){
            int sum=0;
            if(head2!=NULL){
                sum+=head2->val;
                head2=head2->next;
            }
            if(head1!=NULL){
                sum+=head1->val;
                head1=head1->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode * node = new ListNode(sum%10);
            temp->next=node;
            temp=temp->next;
        }
        return head3->next;
        
    }
};