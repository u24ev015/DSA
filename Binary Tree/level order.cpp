class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> levels;
        if(root == NULL) return {};  // if tree is empty

        queue<TreeNode*> q;
        q.push(root);  // start BFS from root

        while(!q.empty()) {
            int size = q.size();     // nodes in current level
            vector<int> temp;

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                temp.push_back(node->val);  // store current level values

                if(node->left != NULL) q.push(node->left);   // push children
                if(node->right != NULL) q.push(node->right);
            }

            levels.push_back(temp);  // store one complete level
        }

        return levels;
    }
};
