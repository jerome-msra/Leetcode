/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    unordered_map<int, int> inordermap;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        for (size_t i = 0; i < inorder.size(); i++)
        {
            inordermap[inorder[i]] = i;
        }
        
        TreeNode * root = nullptr;
        root = buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
        
        return root;
    };
    
    TreeNode * buildTreeHelper(vector<int> inorder, int sin, int ein, vector<int> postorder, int spost, int epost)
    {
        if (sin > ein || spost > epost) return nullptr;
        
        TreeNode * root = new TreeNode(postorder[epost]);
        
        int inorderIdx = inordermap[postorder[epost]];
        int num = inorderIdx - sin;
        
        root->left = buildTreeHelper(inorder, sin, inorderIdx-1, postorder, spost, spost+num-1);
        root->right = buildTreeHelper(inorder, inorderIdx+1, ein, postorder, spost+num, epost-1);
        
        return root;
    };
};
