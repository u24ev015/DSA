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
    ListNode* oddEvenList(ListNode* head) {

        if(head==NULL || head->next==NULL)
        return head;

        ListNode* oddhead=head;
        ListNode* evenhead=head->next;
        ListNode* tempeven=head->next;

        while(evenhead!=NULL && evenhead->next!=NULL)
        {
            oddhead->next=oddhead->next->next;
            oddhead=oddhead->next;
            evenhead->next=evenhead->next->next;
            evenhead=evenhead->next;
        }

        oddhead->next=tempeven;

        return head;

    
    // if(head==NULL || head->next==NULL)
    // return head;

    // ListNode dummy(0);
    // ListNode* temp=&dummy;
    // ListNode* curr=head;
    // while(curr != NULL)  
    // {
    //     ListNode* newnode=new ListNode(curr->val);
    //     temp->next=newnode;
    //     temp=temp->next;
    //     if(curr->next!=NULL)
    //     curr=curr->next->next;
    //     else
    //     curr=NULL;
    // } 

    // curr=head->next;

    // while(curr != NULL)  
    // {
    //     ListNode* newnode=new ListNode(curr->val);
    //     temp->next=newnode;
    //     temp=temp->next;
    //     if(curr->next!=NULL)
    //     curr=curr->next->next;
    //     else
    //     curr=NULL;
    // } 

    // return dummy.next;

    }
};
