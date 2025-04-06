// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75

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
    int max_cnt = 0;

    void dfs(TreeNode* node, bool isLeft, int length)
    {
        if (!node) return;
        max_cnt = max(max_cnt, length);
        if (isLeft)
        {
            dfs(node->left, false, length + 1); 
            dfs(node->right, true, 1); 
        }
        else
        {
            dfs(node->right, true, length + 1);
            dfs(node->left, false, 1); 
        }
    }

public:
    int longestZigZag(TreeNode* root) 
    {
        dfs(root->left, false, 1); 
        dfs(root->right, true, 1); 
        return max_cnt;
    }
};


int main()
{
    BinaryTree tree(1);
    tree.add({1,1,1}, {'R','R','R'});
    tree.add({1,1}, {'R','L'});
    tree.add({1,1,1,1,1}, {'L','L','R','L','L'});
    cout << Solution().longestZigZag(tree.root) << endl;

    BinaryTree tree2(1);
    tree2.add({1,1,1,1}, {'L','R','L','R'});
    tree2.add({1}, {'R'});
    tree2.add({1,1,1}, {'L','R','R'});
    cout << Solution().longestZigZag(tree2.root) << endl;

    return 0;
}
