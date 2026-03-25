/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

void insert(Node*& tail, int val)
{
    Node* newnode = new Node();
    newnode->val = val;
    newnode->next = NULL;
    newnode->child = NULL;

    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

Node* flatten(Node* head) {

    stack<Node*> st;

    Node* dummy = new Node();
    dummy->val = 0;
    dummy->next = NULL;
    dummy->prev = NULL;
    dummy->child = NULL;

    Node* curr = head;
    Node* tail = dummy;

    while(curr != NULL)
    {
        insert(tail, curr->val);

        if(curr->child == NULL)
            curr = curr->next;
        else
        {
            st.push(curr->next);
            curr = curr->child;
        }
    }

    while(!st.empty())
    {
        curr = st.top();
        st.pop();

        while(curr != NULL)
        {
            insert(tail, curr->val);

            if(curr->child == NULL)
                curr = curr->next;
            else
            {
                st.push(curr->next);
                curr = curr->child;
            }
        }
    }

    Node* ans = dummy->next;
    if(ans) ans->prev = NULL;

    return ans;
}
};
