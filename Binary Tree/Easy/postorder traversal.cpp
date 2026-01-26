class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> postorder;
        if(root == NULL) return postorder;   // no nodes

        stack<TreeNode*> st1, st2;

        st1.push(root);  // st1 is used for processing nodes

        // This loop creates a modified preorder: Root -> Left -> Right
        // and stores it into st2, so later we can reverse it to get postorder
        while(!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();

            st2.push(node);  // will later give Left -> Right -> Root

            // push left and right children into st1 for processing
            if(node->left != NULL)  st1.push(node->left);
            if(node->right != NULL) st1.push(node->right);
        }

        // st2 now has nodes in Root -> Right -> Left order
        // popping from it gives Left -> Right -> Root (Postorder)
        while(!st2.empty()) {
            postorder.push_back(st2.top()->val);
            st2.pop();
        }

        return postorder;
    }
};
