// https://leetcode.com/problems/delete-node-in-a-bst/description/?envType=study-plan-v2&envId=leetcode-75

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
			root(new TreeNode(root_value)) 
            {
	}

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

	void _get_inorder(TreeNode* current, vector<int>& values) 
    {
		if (!current)
			return;
		_get_inorder(current->left, values);
		values.push_back(current->val);
		_get_inorder(current->right, values);
	}

	vector<int> get_inorder() 
    {
		vector<int> values;
		_get_inorder(root, values);
		return values;
	}

	bool _search(TreeNode* root, int target) 
    {
		if(!root)
			return false;

		if (target == root->val)
			return true;

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


	bool find_chain(TreeNode* root, int target, vector<TreeNode*> &ancestors) 
    {
		ancestors.push_back(root);

		if (target == root->val)
			return true;

		if (target < root->val)
			return find_chain(root->left, target, ancestors);

		return root->right && find_chain(root->right, target, ancestors);
	}

	int min_value(TreeNode* cur) 
    {
		while (cur && cur->left)
			cur = cur->left;
		return cur->val;
	}

	TreeNode* get_next(vector<TreeNode*> &ancestors) 
    {
		if (ancestors.size() == 0)
			return nullptr;
		TreeNode* node = ancestors.back();	
		ancestors.pop_back();
		return node;
	}

	pair<bool, int> successor(int target) 
    {
		vector<TreeNode*> ancestors;

		if (!find_chain(root, target, ancestors))
			return make_pair(false, -1);

		TreeNode* child = get_next(ancestors);

		if (child->right)	
			return make_pair(true, min_value(child->right));

		TreeNode* parent = get_next(ancestors);

		while (parent && parent->right == child)
			child = parent, parent = get_next(ancestors);

		if (parent)	
			return make_pair(true, parent->val);
		return make_pair(false, -1);
	}



	TreeNode* min_node(TreeNode* cur)
    {
		while (cur && cur->left)
			cur = cur->left;
		return cur;
	}


TreeNode* _delete_node(TreeNode* root, int target) 
{
	if (!root)
		return nullptr;
	if (target < root->val)
		root->left = _delete_node(root->left, target);
	else if (target > root->val)
		root->right = _delete_node(root->right, target);
	else 
    {
		TreeNode* tmp = root;

		if (!root->left && !root->right)	
			root = nullptr;
		else if (!root->right) 				
			root = root->left;					
		else if (!root->left)		
			root = root->right;
		else {							
			TreeNode* mn = min_node(root->right);
			root->val = mn->val;	
			root->right = _delete_node(root->right, root->val);
			tmp = nullptr;	
		}
		if (tmp)
			delete tmp;
	}
	return root;
}

	void delete_node(int target) 
    {
		root = _delete_node(root, target);
	}

};


class Solution 
{
    public:
        TreeNode* deleteNode(TreeNode* root, int key) 
        {
            if(!root)   return nullptr;
            TreeNode* res = BinaryTree(root->val)._delete_node(root, key);
            return res;
        }
};
