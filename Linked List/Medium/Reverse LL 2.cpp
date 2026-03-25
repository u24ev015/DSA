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
    ListNode* reverse(ListNode*& head, int count) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        int cnt = count;

        while (curr != NULL && cnt--) {
            ListNode* nextnode = curr->next;
            curr->next = prev;
            prev = curr;

            curr = nextnode;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int l = left - 1, r = right;
        ListNode* aleft = head;
        ListNode* tleft = NULL;
        ListNode* aright = head;
        ListNode* tright = head;
        while (l--) {
            tleft = aleft;
            aleft = aleft->next;
        }
        while (r--) {
            aright = tright;
            tright = tright->next;
        }
        ListNode* temp = aleft;
        int count = right - left + 1;
        aright = reverse(temp, count);

        if (tleft != NULL)
            tleft->next = aright;
        else
            head = aright;
        aleft->next = tright;
        return head;
    }
};
