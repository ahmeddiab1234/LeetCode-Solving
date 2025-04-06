// https://leetcode.com/problems/leaf-similar-trees/description/?envType=study-plan-v2&envId=leetcode-75


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

void get_leaves(TreeNode* current, vector<int>& nums) 
{
    if (!current) return;
    if (!current->left && !current->right) 
    {
        nums.push_back(current->val);
        return;
    }
    get_leaves(current->left, nums);
    get_leaves(current->right, nums);
}


bool isLeaf(TreeNode *node) 
{
	return node && !node->left && !node->right;
}

class Solution 
{
public:
    bool is_same_leaves(vector<int>& root1, vector<int>& root2)
    {
        if(root1.size() != root2.size())  return false;
        for(int i = 0; i < root1.size(); i++)
        {
            if(root1[i] != root2[i])  return false;
        }
        return true;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> num1, num2;
        get_leaves(root1, num1);
        get_leaves(root2, num2);
        return is_same_leaves(num1, num2);
    }
};


int main()
{
    BinaryTree root1(3);
    root1.add({5,6}, {'L', 'L'});
    root1.add({5,2,7}, {'L', 'R', 'L'});
    root1.add({5,2,4}, {'L', 'R', 'R'});
    root1.add({1,9}, {'R','L'});
    root1.add({1,8}, {'R','R'});
    
    BinaryTree root2(3);
    root2.add({5,6}, {'L', 'L'});
    root2.add({5,7}, {'L', 'R'});
    root2.add({1,4}, {'R', 'L'});
    root2.add({1,2,8}, {'R', 'R', 'R'});
    root2.add({1,2,9}, {'R', 'R', 'L'});

    cout << Solution().leafSimilar(root1.root, root2.root) << endl;

    BinaryTree root3(1);
    root3.add({2}, {'L'});
    root3.add({3}, {'R'});

    BinaryTree root4(1);
    root4.add({3}, {'L'});
    root4.add({2}, {'R'});

    cout << Solution().leafSimilar(root3.root, root4.root) << endl;

    return 0;
}
