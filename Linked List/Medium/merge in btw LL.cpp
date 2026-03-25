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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* slow=list1;
    ListNode* slow2=list1;
    ListNode* fast=list1;
    ListNode* fast2=list1;
    while(a!=0)
    {
        slow2=slow;
        slow=slow->next;
        a--;
    } 
    while(b!=0) 
    {
        fast=fast->next;
        b--;
    }
    fast2=fast->next; 
    ListNode* temp=list2;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    slow2->next=list2;
    temp->next=fast2;
    fast->next=NULL;
    return list1;
       }
};
