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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        int level=1;
        int sum=INT_MIN;
        while(!q.empty())
        {
            int n=q.size();
            int curr_sum=0;
            while(n--)
            {
                auto temp=q.front();
                q.pop();
                curr_sum+=temp->val;
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            if(curr_sum>sum)
            {
                sum=curr_sum;
                ans=level;
            }
            level++;
        }
        return ans;
    }
};