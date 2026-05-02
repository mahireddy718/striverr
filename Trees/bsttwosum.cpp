#include <bits/stdc++.h> 
/***********************************************
	The structure of Binary tree is given below: 
	
	template <typename T>
	class BinaryTreeNode {
	public:
		T data;
		BinaryTreeNode<T>* left;
		BinaryTreeNode<T>* right;

		BinaryTreeNode(T data) {
			this->data = data;
			left = NULL;
			right = NULL;
		}
	};
***********************************************/
void inorder(BinaryTreeNode<int>* root,vector<int>&ans){
	if(root==NULL)return;
	inorder(root->left,ans);
	ans.push_back(root->data);
	inorder(root->right,ans);
}
bool findTargetPair(BinaryTreeNode<int>* root, int target)
{
	vector<int>ans;
	inorder(root,ans);
	int l=0,r=ans.size()-1;
	while(l<r){
		int sum=ans[l]+ans[r];
		if(sum==target)return true;
		else if(sum<target)l++;
		else{
			r--;
		}
	}
	return false;
}