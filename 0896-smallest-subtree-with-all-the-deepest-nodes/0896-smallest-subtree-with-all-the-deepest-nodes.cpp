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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return root;
        unordered_set<TreeNode*> deepest;
        unordered_map<TreeNode*,TreeNode*> parent;
        parent[root]=root;
        queue<TreeNode*> q;
        q.push(root);
        int depth=0;
        while(!q.empty())
        {
            int n=q.size();
            deepest.clear();
            while(n--)
            {
                TreeNode* temp=q.front();
                q.pop();
                deepest.insert(temp);
                if(temp->left!=NULL) 
                {
                    q.push(temp->left);
                    parent[temp->left]=temp;
                }
                if(temp->right!=NULL) 
                {
                    q.push(temp->right);
                    parent[temp->right]=temp;
                }
            }
        }
     
        if(deepest.size()==1) return *deepest.begin();
        while(deepest.size()>1)
        {
            unordered_set<TreeNode*> prev_level;
            for(TreeNode* it:deepest)
            {
                prev_level.insert(parent[it]);
            }
            deepest=prev_level;
        }
        return *deepest.begin();

    }
};