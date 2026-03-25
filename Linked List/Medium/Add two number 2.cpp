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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(l1==NULL)
    return l2;
    else if(l2==NULL)
    return l1;

    l1=reverse(l1);
    l2=reverse(l2);

    ListNode dummy(0);
    ListNode* head=&dummy;
    int carry=0;
    while(l1!=NULL || l2!=NULL)
    {
        int sum=carry;
        if(l1!=NULL)
        {
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL)
        {
            sum+=l2->val;
             l2=l2->next;
        }

        if(sum>9)
        {
            sum=sum%10;
            carry=1;
            ListNode* newnode=new ListNode(sum);
            head->next=newnode;
        }
        else
        {
            carry=0;
            ListNode* newnode=new ListNode(sum);
            head->next=newnode;
        }

        head=head->next;
    }  
    if(carry==1)
    {
         ListNode* newnode=new ListNode(1);
            head->next=newnode;
    } 
    ListNode* headf=reverse(dummy.next); 
    return headf;
        
    }
};
