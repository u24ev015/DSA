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
    ListNode* reverse(ListNode* &head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;

        while(curr!=NULL)
        {
            ListNode* nextnode=curr->next;
            curr->next=prev;
            prev=curr;

            curr=nextnode;   
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
    if(head==NULL || head->next==NULL)return head;
    head=reverse(head);
    ListNode* temp=head;
    int maxi=INT_MIN;
    while(temp!=NULL)
    {
        maxi=max(maxi,temp->val);
        if(temp->next!=NULL && maxi>temp->next->val)
        {
            temp->next=temp->next->next;
        }
        else
        {
            temp=temp->next;
        }
    }
    head=reverse(head);
    return head;
    }
};
