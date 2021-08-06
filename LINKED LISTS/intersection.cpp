//160. Intersection of Two Linked Lists
//BRUTEFORCE-> for each node in a linked list, compare every other node in other linked list. If they're same return that node
//OPTIMIZE-> use hashing. traverse linked list and hash the node address of the linked list. Find which node's address is already stored for other linnked list
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB ==NULL) return NULL;
        ListNode *head1=headA;
        ListNode * head2=headB;
        while(head1!=head2){
            if(head1==NULL) head1=headB;
            else head1=head1->next;
            if(head2==NULL) head2=headA;
            else head2=head2->next;
    
        }
        if(head1==head2)
        return head1;
        return NULL;
        
    }
};