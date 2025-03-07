/* Binary Tree Inorder Traversal
    Enact inorder traversal using recursion and DFS.
*/
class Solution {
    /* inorderTraversal(TreeNode* root)
        Method: Depth-first search
        Return type: vector<int>
        1. Create result vector variable.
        2. Conduct DFS upon the tree.
        3. Return the result.
    */
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int>res;
            DFS(root,res);
            return res;
        }
    
    /* DFS(TreeNode* r, vector<int>& res)
        Method: Recursion
        Return type: void
        1. If the pointer node is NULL, return.
        2. Conduct DFS on the left node.
        3. Push the value to the back of the result.
        4. Conduct DFS on the right node.
    */
    private:
        void DFS(TreeNode* r, vector<int>& res)
        {
            if (r==NULL)
                return;
            DFS(r->left,res);
            res.push_back(r->val);
            DFS(r->right,res);
        }
};
