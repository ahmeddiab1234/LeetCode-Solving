// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val { };
	TreeNode *left { };
	TreeNode *right { };
	TreeNode(int val) :
			val(val) {
	}
};

struct BinaryTree 
{
    public:
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
    
};
    
class Solution 
{
public:
    int maxDepth(TreeNode *root) 
    {
        if(!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) +1;
    }

};