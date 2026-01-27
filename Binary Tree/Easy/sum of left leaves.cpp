int sumOfLeftLeaves(TreeNode* root) {
    // TC: O(n) — each node is visited once
    // SC: O(n) — stack space in worst case (skewed tree)

    // Empty tree
    if (root == NULL) return 0;

    // Stack for DFS traversal
    stack<TreeNode*> st;
    st.push(root);
    int sum = 0;

    while (!st.empty()) {
        root = st.top();
        st.pop();

        // Check left child
        if (root->left) {
            // If left child is a leaf, add its value
            if (!root->left->left && !root->left->right)
                sum += root->left->val;

            // Continue traversal
            st.push(root->left);
        }

        // Traverse right child
        if (root->right)
            st.push(root->right);
    }

    return sum;
}
