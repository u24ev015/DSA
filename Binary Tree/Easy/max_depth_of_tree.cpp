class Solution {
public:
    // TC: O(n)  (visits every node once)
    // SC: O(h)  (recursion stack, h = height of tree)
    int maxDepth(TreeNode* root) {

        if(root == NULL) return 0;   // base case: empty tree has depth 0

        int l = maxDepth(root->left);   // depth of left subtree
        int r = maxDepth(root->right);  // depth of right subtree

        return 1 + max(l, r);  // 1 for current node + max of both sides
    }
};
