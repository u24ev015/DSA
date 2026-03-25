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
    ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL)
    return head;
    ListNode* temp=head;
    int cnt=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        cnt++;
    }
    cnt=k%cnt;
    ListNode* slow=head;
    ListNode* fast=head;
    while(cnt!=0)
    {
        fast=fast->next;
        cnt--;
        if(fast==NULL)
        fast=head;
    } 
    if(fast==head)
    return head;

    while(fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    ListNode* newhead=slow->next;
    slow->next=NULL;
    fast->next=head;
    return newhead;
    }
};
