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
	void insertNode(int value)
	{
		TreeNode* newNode = new TreeNode(value);
		if (root == nullptr)
		{
			root = newNode;
			return;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode* current = q.front();
			q.pop();

			if (current->left == nullptr)
			{
				current->left = newNode;
				return;
			}
			else
			{
				q.push(current->left);
			}

			if (current->right == nullptr)
			{
				current->right = newNode;
				return;
			}
			else
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
	/*void deleteNode(int value)
	{
		TreeNode* temp = root;
		TreeNode* temp1 = nullptr;
		bool flag = false;
		while (temp && flag == false)
		{
			if (temp->data == value)
			{
				flag = true;
			}
			else if(temp)
		}
	}*/
	int findHeight(TreeNode* node)
	{
		static int height = 0;
		if (node == nullptr)
		{
			return -1;
		}
		height++;
		findHeight(node->left);
		return height;
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
		cout << leftHeight << " " << rightHeight << " ";
		if (leftHeight == rightHeight || leftHeight + 1 == rightHeight || leftHeight == rightHeight + 1)
		{
			return true;
		}
		return false;
	}
	bool search(TreeNode* node, int value)
	{
		if (node == nullptr)
		{
			return false;
		}
		if (node->data == value)
		{
			return true;
		}
		return search(node->left, value) || search(node->right, value);
	}
	void swap(TreeNode*& a, TreeNode*& b)
	{
		TreeNode* temp = a;
		a = b;
		b = temp;
	}
	TreeNode* mirrorTree(TreeNode* root)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		TreeNode* temp = root;
		mirrorTree(temp->right);
		mirrorTree(temp->left);
		swap(temp->left, temp->right);
		return temp;
	}
	int transformToSumTree(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		root->data = root->data + transformToSumTree(root->left) + transformToSumTree(root->right);
		return root->data;
	}
	void deleteNode(TreeNode* root, int key)
	{
		TreeNode* temp = root;
		TreeNode* temp2 = root;
		bool flag = false;
		while (temp != nullptr && !flag)
		{
			if (temp->data > key)
			{
				temp2 = temp;
				temp = temp->left;
			}
			else if (temp->data < key)
			{
				temp2 = temp;
				temp = temp->right;
			}
			else
				flag = true;
		}
		if (flag)
		{

		}
		else
			cout << "\nNode is not present";
	}
};
int main()
{
	BinarySearchTree bt;
	int nodes, n;
	cout << "Enter number of nodes: ";
	cin >> nodes;
	for (int i = 1; i <= nodes; i++)
	{
		cin >> n;
		bt.insertNode(n);
	}
	cout << bt.transformToSumTree(bt.getRoot());
	cout << " ";
	bt.inOrder(bt.getRoot());
	/*cout << "Original Tree\n";
	bt.inOrder(bt.getRoot());
	cout << " ";
	cout << "\nMirrored Tree\n";
	TreeNode* temp1 = bt.mirrorTree(bt.getRoot());
	bt.inOrder(temp1);*/
	return 0;
}