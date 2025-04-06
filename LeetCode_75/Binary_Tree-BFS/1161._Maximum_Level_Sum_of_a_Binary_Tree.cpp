// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75

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
    int level_order(TreeNode* root) 
    {
		queue<TreeNode*> nodes_queue;
		nodes_queue.push(root);

        int max_num=INT_MIN;
        int res=1;
		int level = 1;
		while (!nodes_queue.empty()) 
        {
			int sz = nodes_queue.size();

            int sum=0;
			while(sz--) 
            {
                TreeNode*cur = nodes_queue.front();
				nodes_queue.pop();

                sum+=cur->val;

				if (cur && cur->left)
					nodes_queue.push(cur->left);
				if (cur && cur->right)
					nodes_queue.push(cur->right);
			}
            if(max_num < sum)
            {
                max_num = sum;
                res = level;
            }
			level++;
		}
        return res;
	}
    public:
    int maxLevelSum(TreeNode* root) 
    {
        return level_order(root);
    }
};

int main()
{
    BinaryTree tree(1);
    tree.add({7, 7}, {'L', 'L'});
    tree.add({7, -8}, {'L', 'R'});
    tree.add({0}, {'R'});
    cout << Solution().maxLevelSum(tree.root) << endl;

    return 0;
}
