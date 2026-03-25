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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    if(head==NULL)
    return NULL;
    
    ListNode* fast = head;
    ListNode* slow = head;

    for(int i=0;i<n;i++)
    {
        fast=fast->next;
    }

    if(fast==NULL)
    {
        ListNode* del=head;
        head=head->next;
        delete del;
        return head;
    }

    ListNode* store=slow;
    while(fast!=NULL)
    {
        store=slow;
        slow=slow->next;
        fast=fast->next;
    }

    store->next=store->next->next;
    delete slow;

    return head;

    }
};
