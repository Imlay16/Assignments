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

		Find(node->left, data);
		Find(node->right, data);

		return nullptr;
	}

	TreeNode* AddRecursive(TreeNode* node, int data)
	{
		if (node->data >= data && node->left == nullptr) return node;

		if (node->data < data && node->right == nullptr) return node;

		if (node->data >= data) return AddRecursive(node->left, data);
		else return AddRecursive(node->right, data);
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

public:
	BinaryTree() { }
	~BinaryTree()
	{
		// ��ȸ�ϸ鼭 ����
		// �������� ��Ʈ��� ����?
		
		
		delete root;
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
		// ������ ��,
		// 1. �ڽ��� ���� ���
		// 2. �ڽ��� �ϳ� �ִ� ���
		// 3. �ڽ��� ���� ���	
		

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