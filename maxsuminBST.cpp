//Maximum Sum BST in Binary Tree
/*Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
/*
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

class info{

public:
int maxi;
int mini;
int size;
bool isBST;
};
info solve(TreeNode* root, int &ans){
    if(root == NULL){
        return{INT_MIN, INT_MAX , 0  ,true};
    }

    info left = solve(root->left,ans);
    info right = solve(root->right,ans);


    info currnode;
    currnode.size = left.size+right.size+root->val;
    currnode.maxi = max(root->val,right.maxi);
    currnode.mini = min(root->val,left.mini);

    if(left.isBST && right.isBST && (root->val >left.maxi && root->val<right.mini)){
        currnode.isBST=true;
    }
    else{
        currnode.isBST=false;
    }
    if(currnode.isBST){
        ans = max(ans,currnode.size);
    }
    return currnode;

}
int maxSumBST(TreeNode* root ) {
    int maxisize=0;
   info temp = solve(root,maxisize); 
   return maxisize;    
    }
};
