// https://leetcode.com/problems/binary-tree-right-side-view/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode 
{
	int val { };
	TreeNode *left { };
	TreeNode *right { };
	TreeNode(int val) :
			val(val) {}
};

struct BinaryTree 
{
	TreeNode *root { };
	BinaryTree(int root_value) :
			root(new TreeNode(root_value)) {}

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
    vector<int> level_order(TreeNode* root) 
    {
        vector<int> result;
		queue<TreeNode*> nodes_queue;
		nodes_queue.push(root);

		int level = 0;
		while (!nodes_queue.empty()) 
        {
			int sz = nodes_queue.size();

			while(sz--) 
            {
				TreeNode* cur = nodes_queue.front();
				nodes_queue.pop();

				if (cur && cur->left)
					nodes_queue.push(cur->left);
				if (cur && cur->right)
					nodes_queue.push(cur->right);
                if(sz==0 && cur)   result.push_back(cur->val);
			}
			level++;
		}
        return result;
    }
    public:
        vector<int> rightSideView(TreeNode* root) 
        {
            vector<int> res = level_order(root);
            return res;
        }
};

int main()
{
    BinaryTree tree(1);
    tree.add({2, 5}, {'L', 'R'});
    tree.add({3, 4}, {'R', 'R'});
    vector<int> res = Solution().rightSideView(tree.root);
    for(auto v : res)   cout << v << ' ';

    return 0;
}
