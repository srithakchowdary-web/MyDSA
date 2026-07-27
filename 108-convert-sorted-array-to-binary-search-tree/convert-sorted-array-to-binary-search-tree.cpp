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
    TreeNode* insert(vector<int>& nums, int lt, int rt){
        if(lt > rt) {
            return NULL;
        }
        int mid = lt + (rt-lt) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = insert(nums,lt,mid-1);
        root->right = insert(nums,mid+1,rt);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        // TreeNode*
        return insert(nums, 0, n-1);
    }
};