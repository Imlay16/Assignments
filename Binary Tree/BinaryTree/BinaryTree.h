#pragma once
#include <iostream>

using namespace std;

struct TreeNode 
{
	int data;
	TreeNode* left;
	TreeNode* right;
};

class BinaryTree
{
private:
	TreeNode* root = nullptr;

	TreeNode* Find(TreeNode* node, int data)
	{
		if (node == nullptr) return nullptr;

		if (node->data == data)
			return node;

		if (node->data > data)
		{
			return Find(node->left, data);
		}
		else
		{
			return Find(node->right, data);
		}
	}

	TreeNode* AddRecursive(TreeNode* node, int data)
	{
		if (node->data >= data && node->left == nullptr) return node;

		if (node->data < data && node->right == nullptr) return node;

		if (node->data >= data) return AddRecursive(node->left, data);
		else return AddRecursive(node->right, data);
	}

	TreeNode* RemoveRecursive(TreeNode* node, int data)
	{
		if (node == nullptr) return nullptr;

		if (node->data == data)
		{
			// ��Ʈ �����ϴ� ��쵵 ����ؾ���..!

			// ���� ���� + ���� Ʈ�� ���� 
			
			// �ڽ��� ���� ���
			if (node->left == nullptr && node->right == nullptr)
			{
				// �׳� ����
				delete node;
				return nullptr;
			}
			// �ڽ��� �ϳ��� ���
			else if ((node->left != nullptr) || (node->right != nullptr))
			{
				// �θ�� �ڽ��� �ٲ����.
				TreeNode* child;
				if (node->left != nullptr)
				{
					child = node->left;
				}
				else
				{
					child = node->right;
				}

				delete node;
				return child;
			}			

			// �ڽ��� ���� ���
			else if (node->left != nullptr && node->right != nullptr)
			{
				// ���� ���� Ʈ���� �ִ� OR ������ ���� Ʈ���� �ּڰ�.
				// � ���� �������� ���ؾ���.


			}
		}

		if (node->data > data)
		{
			// ���ϰ�? = RemoveRecursive(node->left, data);
			// ������ �Ǹ� �� �� �ϳ�. nullptr or ������ node�� ����
			node->left = RemoveRecursive(node->left, data);
		}
		else
		{
			// ���ϰ�? = RemoveRecursive(node->right, data);
			// ������ �Ǹ� �� �� �ϳ�. nullptr or ������ node�� ����
			node->right = RemoveRecursive(node->right, data);			
		}
	}

	void PreOrderRecursive(TreeNode* node)
	{
		if (node == nullptr) return;

		cout << node->data << " ";
		PreOrderRecursive(node->left);
		PreOrderRecursive(node->right);
	}

	void InOrderRecursive(TreeNode* node)
	{
		if (node == nullptr) return;

		InOrderRecursive(node->left);
		cout << node->data << " ";
		InOrderRecursive(node->right);
	}

	void PostOrderRecursive(TreeNode* node)
	{
		if (node == nullptr) return;

		PostOrderRecursive(node->left);
		PostOrderRecursive(node->right);
		cout << node->data << " ";
	}

	void ClearNode(TreeNode* node)
	{
		if (node == nullptr) return;

		ClearNode(node->left);
		ClearNode(node->right);

		delete node;
	}

public:
	BinaryTree() { }
	~BinaryTree()
	{
		// ��ȸ�ϸ鼭 ����
		// Left - Right - Root ������ delete �ؾ���. PostOrder.
		ClearNode(root);
		root = nullptr;
	}
	
	// ��ͷ� ����
	void Add(int data)
	{
		if (root == nullptr)
		{
			root = new TreeNode{ data, nullptr, nullptr };
		}
		else
		{
			TreeNode* leafNode = AddRecursive(root, data);
			
			if (leafNode->data >= data)
			{
				leafNode->left = new TreeNode{ data, nullptr, nullptr };
			}
			else if (leafNode->data < data)
			{
				leafNode->right = new TreeNode{ data, nullptr, nullptr };
			}
		}
	}

	void Remove(int data)
	{
		TreeNode* removeNode = RemoveRecursive(root, data);

		if (removeNode == nullptr)
		{
			return;
		}
		else
		{
			
		}


	}

	bool Contains(int data)
	{
		if (Find(root, data) != nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// ��ȸ
	void PreOrder()
	{
		PreOrderRecursive(root);
		cout << endl;
	}

	void InOrder()
	{
		InOrderRecursive(root);
		cout << endl;
	}

	void PostOrder()
	{
		PostOrderRecursive(root);
		cout << endl;
	}
};