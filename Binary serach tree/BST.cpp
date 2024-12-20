#include<iostream>
using namespace std;
#include<queue>
struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int d, TreeNode* l = nullptr, TreeNode* r = nullptr)
	{
		data = d;
		left = l;
		right = r;
	}
};
class BinarySearchTree
{
	TreeNode* root;
public:
	BinarySearchTree(TreeNode* r = nullptr)
	{
		root = r;
	}
	TreeNode*& getRoot()
	{
		return root;
	}
	void insertNode(TreeNode* node, int value)
	{
		if (node == nullptr)
		{
			root = new TreeNode(value);
			return;
		}
		TreeNode* temp = node;
		TreeNode* temp1 = nullptr;
		bool flag = false;
		while (temp && flag == false)
		{
			if (temp->data == value)
			{
				flag = true;
			}
			else if (temp->data > value)
			{
				temp1 = temp;
				temp = temp->left;
			}
			else if (temp->data < value)
			{
				temp1 = temp;
				temp = temp->right;
			}
		}
		if (flag)
		{
			cout << "Value already exits.\n";
			return;
		}
		else
		{
			if (value < temp1->data)
			{
				temp1->left = new TreeNode(value);
			}
			else
			{
				temp1->right = new TreeNode(value);
			}
		}
	}
	void levelOrder(TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode* current = q.front();
			q.pop();
			cout << current->data << " ";
			if (current->left != nullptr)
			{
				q.push(current->left);
			}
			if (current->right != nullptr)
			{
				q.push(current->right);
			}
		}
	}
	void inOrder(TreeNode* node)
	{
		if (node == nullptr)
		{
			return;
		}
		inOrder(node->left);
		cout << node->data << ' ';
		inOrder(node->right);
	}
	void preOrder(TreeNode* node)
	{
		if (node == nullptr)
		{
			return;
		}
		cout << node->data << ' ';
		preOrder(node->left);
		preOrder(node->right);
	}
	void postOrder(TreeNode* node)
	{
		if (node == nullptr)
		{
			return;
		}
		postOrder(node->left);
		postOrder(node->right);
		cout << node->data << ' ';
	}
	int findHeight(TreeNode* node)
	{
		if (node == nullptr)
		{
			return -1;
		}
		int leftHeight = findHeight(node->left);
		int rightHeight = findHeight(node->right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
	int countNodes(TreeNode* node)
	{
		static int i = 0;
		if (node == nullptr)
		{
			return i;
		}
		i++;
		countNodes(node->left);
		countNodes(node->right);
		return i;
	}
	bool isBalanced(TreeNode* node)
	{
		int leftHeight = findHeight(node->left);
		int rightHeight = findHeight(node->right);
		if (leftHeight == rightHeight || leftHeight + 1 == rightHeight || leftHeight == rightHeight + 1)
		{
			return true;
		}
		return false;
	}
	bool search(TreeNode* node, int value)
	{
		TreeNode* temp = node;
		bool flag = false;
		while (temp && flag == false)
		{
			if (temp->data == value)
			{
				flag = true;
			}
			else if (temp->data > value)
			{
				temp = temp->left;
			}
			else if (temp->data < value)
			{
				temp = temp->right;
			}
		}
		return flag;
	}
	TreeNode* findSuccessor(TreeNode* node) 
	{
		while (node->left)
		{
			node = node->left;
		}
		return node;
	}
	TreeNode* findPredecessor(TreeNode* node)
	{
		while (node->right)
		{
			node = node->right;
		}
		return node;
	}
	TreeNode* deleteNode(TreeNode* node, int key)
	{
		if (node == nullptr) 
		{
			return node; 
		}
		if (key < node->data)
		{
			node->left = deleteNode(node->left, key);
		}
		else if (key > node->data)
		{
			node->right = deleteNode(node->right, key);
		}
		else 
		{
			if (node->left == nullptr && node->right == nullptr)
			{
				delete node;
				return nullptr;
			}
			else if (node->left == nullptr)
			{
				TreeNode* temp = node->right;
				delete node;
				return temp;
			}
			else if (node->right == nullptr)
			{
				TreeNode* temp = node->left;
				delete node;
				return temp;
			}
			else
			{
				TreeNode* temp = findSuccessor(node->right);
				node->data = temp->data;
				node->right = deleteNode(node->right, temp->data);
			}
		}
		return node;
	}
};
int main()
{
	BinarySearchTree bst;
	/*for (int i = 1; i <= 7; i++)
	{
		bst.insertNode(bst.getRoot(), i);
	}*/
	bst.insertNode(bst.getRoot(), 20);
	bst.insertNode(bst.getRoot(), 8);
	bst.insertNode(bst.getRoot(), 13);
	bst.insertNode(bst.getRoot(), 25);
	bst.insertNode(bst.getRoot(), 50);
	bst.insertNode(bst.getRoot(), 2);
	bst.insertNode(bst.getRoot(), 37);
	bst.levelOrder(bst.getRoot());
	cout << "\n";
	TreeNode* temp = bst.deleteNode(bst.getRoot(), 8);
	bst.levelOrder(temp);
	return 0;
}