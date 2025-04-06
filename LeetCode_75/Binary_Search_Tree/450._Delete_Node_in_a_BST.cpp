// https://leetcode.com/problems/search-in-a-binary-search-tree/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

struct TreeNode 
{
	int val { };
	TreeNode* left { };
	TreeNode* right { };
	TreeNode(int val) : val(val) { }
};


struct BinaryTree 
{
	TreeNode* root { };
	BinaryTree(int root_value) :
			root(new TreeNode(root_value)) { }

	void add(vector<int> values, vector<char> direction) 
    {
		assert(values.size() == direction.size());
		TreeNode* current = this->root;
		for (int i = 0; i < (int) values.size(); ++i) 
        {
			if (direction[i] == 'L') 
            {
				if (!current->left)
					current->left = new TreeNode(values[i]);
				else
					assert(current->left->val == values[i]);
				current = current->left;
			} 
            else 
            {
				if (!current->right)
					current->right = new TreeNode(values[i]);
				else
					assert(current->right->val == values[i]);
				current = current->right;
			}
		}
	}

	void _print_inorder(TreeNode* current) 
    {
		if (!current)
			return;
		_print_inorder(current->left);
		cout << current->val << " ";
		_print_inorder(current->right);
	}


	void print_inorder() 
    {
		_print_inorder(root);
		cout << "\n";
	}

	TreeNode* _search(TreeNode* root, int target) 
    {	
        TreeNode* res=nullptr;
		if(!root)
			return nullptr;

		if (target == root->val)
		{
            res = root;
            return root;
        }

		if (target < root->val)
			return _search(root->left, target);

		return _search(root->right, target);
	}

	bool search(int target) 
    {
		return _search(root, target);
	}

	void _insert(TreeNode* root, int target) 
    {
		if (target < root->val) 
        {
			if (!root->left)
				root->left = new TreeNode(target);
			else
				_insert(root->left, target);
		} 
        else if(target > root->val)
        {
			if (!root->right)
				root->right = new TreeNode(target);
			else
				_insert(root->right, target);
		} 
	}

	void insert(int target) {
		if (!root)
			root = new TreeNode(target);
		else
			_insert(root, target);
	}

};

class Solution 
{
    public:
        TreeNode* searchBST(TreeNode* root, int val) 
        {
            TreeNode* res = BinaryTree(root->val)._search(root, val);
            return res;
        }
};
