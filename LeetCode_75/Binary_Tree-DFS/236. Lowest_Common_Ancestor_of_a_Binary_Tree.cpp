// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;


struct TreeNode 
{
	int val { };
	TreeNode *left { };
	TreeNode *right { };
	TreeNode(int val) :
			val(val) {
	}
};

struct BinaryTree 
{
	TreeNode *root { };
	BinaryTree(int root_value) :
			root(new TreeNode(root_value)) 
            {
	}

	void add(vector<int> values, vector<char> direction) 
    {
		assert(values.size() == direction.size());
		TreeNode *current = this->root;
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
    
};

class Solution 
{
    public:
        TreeNode* lca(TreeNode* cur, TreeNode* p, TreeNode* q) 
        {
            if (!cur) return nullptr;
            if (cur->val == p->val || cur->val == q->val) return cur;

            TreeNode* left = lca(cur->left, p, q);
            TreeNode* right = lca(cur->right, p, q);

            if (left && right) return cur;
            return left ? left : right;
        }

        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
        {
            return lca(root, p, q);
        }
};


int main()
{
	BinaryTree tree(3);
	tree.add({5, 6}, {'L', 'L'});
	tree.add({5, 2, 7}, {'L', 'R', 'L'});
	tree.add({5, 2, 4}, {'L', 'R', 'R'});
	tree.add({1, 0}, {'R', 'L'});
	tree.add({1, 8}, {'R', 'R'});

	BinaryTree p(5);
	BinaryTree q(1);
	
	TreeNode* lca_node = Solution().lowestCommonAncestor(tree.root, p.root, q.root);
	cout << lca_node->val << endl;

    return 0;
}
