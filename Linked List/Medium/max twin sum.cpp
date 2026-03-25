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
    int pairSum(ListNode* head) {
    ListNode* slow=head;
    ListNode* fast=head;
    ListNode* slowprev=slow;
    while(fast!=NULL){
        slowprev=slow;
        fast=fast->next->next;
        slow=slow->next;
        
    }
    slowprev->next=NULL;
    ListNode* head2=reverse(slow);
    ListNode* temp1=head;
    ListNode* temp2=head2;
    int maxi=INT_MIN;
    while(temp1!=NULL && temp2!=NULL)
    {
        maxi=max(maxi,temp1->val+temp2->val);
        temp1=temp1->next;
        temp2=temp2->next;

    }
    return maxi;
    }
};
