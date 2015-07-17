// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>

struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
	//TreeNode * next;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool DLS(TreeNode * root, int depth)
{
	if (root == NULL)
	{
		return false;
	}
	else if (depth == 0)
	{
		std::cout << root->val << " ";
		return true;
	}
	else
	{
		std::cout << root->val << " ";
		bool dlsleft = DLS(root->left, depth-1);
		if (!dlsleft)
		{
			return false;
		}
		return DLS(root->right, depth-1);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{

	TreeNode * root = new TreeNode(1);
	TreeNode * node2 = new TreeNode(2);
	TreeNode * node3 = new TreeNode(3);
	TreeNode * node4 = new TreeNode(4);
	TreeNode * node5 = new TreeNode(5);
	TreeNode * node6 = new TreeNode(6);
	TreeNode * node7 = new TreeNode(7);
	root->left = node2;
	root->right = node3;

	node2->left = node4; node2->right = node5;
	node3->left = node6; node3->right = node7;

	int depth = 0;
	while (DLS(root, depth))
	{
		depth++;
		std::cout << std::endl;
	}

	return 0;
}
