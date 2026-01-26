class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> preorder;
        if(root == NULL) return preorder;  // empty tree

        stack<TreeNode*> st;
        st.push(root);  // start from root

        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            preorder.push_back(node->val);  // visit node (Root)

            // push right first so left is processed first
            if(node->right != NULL) st.push(node->right);
            if(node->left != NULL)  st.push(node->left);
        }

        return preorder;
    }
};
