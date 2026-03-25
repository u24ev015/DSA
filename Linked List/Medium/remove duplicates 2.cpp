class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;

        stack<int> st;
        ListNode* temp = head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while(temp != NULL) {

            if(temp->next != NULL && temp->val == temp->next->val) {

                st.push(temp->val);

                while(temp != NULL && temp->val == st.top()) {
                    ListNode* delnode = temp;
                    temp = temp->next;
                    delete delnode;
                }

                prev->next = temp;   
                st.pop();
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }

        return dummy->next;
    }
};
