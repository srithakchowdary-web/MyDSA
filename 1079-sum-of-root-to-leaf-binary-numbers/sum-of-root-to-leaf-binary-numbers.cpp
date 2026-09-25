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
 //binary to num -> num*2 + val ;
class Solution {
public:
    int solve(int num, TreeNode* root){
        if(root == NULL) return 0;
        num = num*2 + root->val ;
        if(root->left == NULL && root->right == NULL)   return num;
        return solve(num, root->left)+solve(num, root->right)  ;
    }
    int sumRootToLeaf(TreeNode* root) {
        int num=0;
        num = solve(num, root);
        return num;
    }
};