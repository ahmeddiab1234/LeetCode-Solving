// https://leetcode.com/problems/path-sum-iii/description/?envType=study-plan-v2&envId=leetcode-75

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
    void dfs(TreeNode* node, long long current_sum, int targetSum, int &cnt)
    {
        if (!node) return;
        current_sum += node->val;
        if (current_sum == targetSum) cnt++;
        dfs(node->left, current_sum, targetSum, cnt);
        dfs(node->right, current_sum, targetSum, cnt);
    }

    void count_target(TreeNode* node, int targetSum, int &cnt)
    {
        if (!node) return;
        dfs(node, 0, targetSum, cnt);
        count_target(node->left, targetSum, cnt);
        count_target(node->right, targetSum, cnt);
    }

public:
    int pathSum(TreeNode* root, int targetSum) 
    {
        int cnt = 0;
        count_target(root, targetSum, cnt);
        return cnt;
    }
};


int main()
{
    BinaryTree tree(10);
    tree.add({5, 3, 3}, {'L', 'L', 'L'});
    tree.add({5, 3, -2}, {'L', 'L', 'R'});
    tree.add({5, 2, 1}, {'L', 'R', 'R'});
    tree.add({-3, 11}, {'R', 'R'});
    cout << Solution().pathSum(tree.root, 8)  << endl;

    return 0;
}
