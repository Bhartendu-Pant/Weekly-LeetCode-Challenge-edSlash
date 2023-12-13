/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

//Solution:
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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        queue<pair<int,TreeNode*>>q;
        map<int,int>mpp;
        q.push({0,root});

        while(!q.empty())
        {
            auto frontNode=q.front();
            q.pop();
            TreeNode* myNode=frontNode.second;
            int level=frontNode.first;
            if(mpp.find(level)==mpp.end())mpp[level]=myNode->val;
            if(myNode->right)q.push({level+1,myNode->right});
            if(myNode->left)q.push({level+1,myNode->left});
        }
        vector<int>ans;
        for(auto el:mpp)
        {
            ans.push_back(el.second);
        }
        return ans;
    }
};
