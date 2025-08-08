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

	TreeNode* FindMin(TreeNode* node)
	{
		if (node == nullptr) return nullptr;

		if (node->left == nullptr) return node;

		return FindMin(node->left);
	}

	TreeNode* AddRecursive(TreeNode* node, int data)
	{
		if (node == nullptr) return new TreeNode{ data, nullptr, nullptr };

		if (node->data > data)
		{
			node->left = AddRecursive(node->left, data);
		}

		if (node->data < data)
		{
			node->right = AddRecursive(node->right, data);
		}
		
		return node;
	}	

	TreeNode* RemoveRecursive(TreeNode* node, int data)
	{
		if (node == nullptr) return nullptr;

		if (node->data == data)
		{
			// ���� ���� + ���� Ʈ�� ���� 
			
			// �ڽ��� ���� ���
			if (node->left == nullptr && node->right == nullptr)
			{
				// �׳� ����
				delete node;
				return nullptr;
			}
			// �ڽ��� �ϳ��� ���
			else if ((node->left == nullptr) != (node->right == nullptr))
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
				
				// ������ ���� Ʈ���� �ּڰ� ã��
				TreeNode* successor = FindMin(node->right);
				node->data = successor->data;

				node->right = RemoveRecursive(node->right, successor->data);
				return node;
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

		return node;
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
		root = AddRecursive(root, data);
	}

	void Remove(int data)
	{
		root = RemoveRecursive(root, data);
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