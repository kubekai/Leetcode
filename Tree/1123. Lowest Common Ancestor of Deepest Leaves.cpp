/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxdeep = maxDepth(root);
        return dfs(root,maxdeep,0);

        
    }
    TreeNode* dfs(TreeNode* node,int maxdeep,int currdeep){
        if(!node)return NULL;
        if(currdeep == maxdeep-1) return node; //到最深層
        TreeNode* left = dfs(node->left,maxdeep,currdeep+1);
        TreeNode* right = dfs(node->right,maxdeep,currdeep+1);
        if(left && right){//如果左右都有的話代表是LCA
            return node;//就回傳subtree
        }
        return left ? left : right;//left不是null回傳left，left是null回傳right
        

    }
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int deep = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            deep++;
        }
        return deep;
        
    }
};
